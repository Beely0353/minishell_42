/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:36:54 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/13 15:24:04 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_env *envlst, t_minishell *g_minishell)
{
	g_minishell->re = 0;
	while (envlst)
	{
		printf("%s=%s\n", envlst->name, envlst->value);
		envlst = envlst->next;
	}
}
