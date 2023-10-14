/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:27:06 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/11 13:39:14 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(char	*envp)
{
	char	*name;
	int		i;

	i = 0;
	while (envp[i] != '=')
		i++;
	name = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (envp[++i] != '=')
		name[i] = envp[i];
	name[i] = '\0';
	return (name);
}

char	*get_value(char	*envp)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	while (envp[i] != '=')
		i++;
	i++;
	j = i;
	while (envp[i])
		i++;
	value = malloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (envp[j])
		value[i++] = envp[j++];
	value[i] = '\0';
	return (value);
}

void	get_envlst(char **envp, t_env *envlst)
{
	int	i;

	i = 0;
	while (envp[++i])
		ft_lstadd_back(envlst, \
		ft_lstnew(get_name(envp[i]), get_value(envp[i])));
}
