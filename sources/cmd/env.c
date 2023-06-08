/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:36:54 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/08 12:10:00 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_env *envlst, t_minishell *g_minishell)
{
	(void) g_minishell;
	while (envlst)
	{
		ft_putstr_fd(envlst->name, 1);
		write(1, "=", 1);
		ft_putstr_fd(envlst->value, 1);
		write(1, "\n", 1);
		envlst = envlst->next;
	}
}
