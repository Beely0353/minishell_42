/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mybin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:54:37 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/23 17:19:43 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_bin(t_minishell *mini)
{
	int	*c;
	DIR* dir;
	int	i;
	struct dirent*	entry;
	
	dir = opendir("/bin");i
	i = 0;
	if (dir = NULL)
	{
		perror("Error open /bin");
		*c = 0;
		return (NULL);
	}
	mini->binlist = malloc(sizeof(char **) * 35);
	entry = readdir(dir);
	while (entry != NULL)
	{
		mini->binlist[i] = malloc(sizeof(char) * ft_strlen(entry->d_name) + 1);
		if (mini->binlist[i] == NULL)
		{
			perror("Erreur lors de l'allocation de mémoire");
			*c = i;
			closedir(dir);
			free_binlist(mini->binlist, i);
			return (NULL);
		}
		ft_strcpy(miin->binlist[i], entry->d_name);
		i++;
	}
	closedir(dir);
}

