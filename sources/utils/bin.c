/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:10:52 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/26 17:17:40 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_bin(t_minishell *mini)
{
	int				*c;
	DIR				*dir;
	int				i;
	struct dirent	*entry;

	dir = opendir("/bin");
	i = 0;
	if (dir == NULL)
		return (NULL);
	mini->binlist = malloc(sizeof(char **) * 35);
	entry = readdir(dir);
	while (entry != NULL)
	{
		mini->binlist[i] = malloc(sizeof(char) * ft_strlen(entry->d_name) + 1);
		if (mini->binlist[i] == NULL)
		{
			closedir(dir);
			free_binlist(mini->binlist, i);
			return (NULL);
		}
		ft_strcpy(mini->binlist[i], entry->d_name);
		i++;
	}
	closedir(dir);
}

void	pideror(void)
{
	perror("pid");
	exit(EXIT_FAILURE);
}
