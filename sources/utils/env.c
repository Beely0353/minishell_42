/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:34:47 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/13 16:35:05 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char *name, t_env *envlst)
{
	while (envlst)
	{
		if (ft_strcmp(name, envlst->name) == 0)
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
}
