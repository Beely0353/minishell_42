/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:43:14 by biaroun           #+#    #+#             */
/*   Updated: 2023/07/04 17:12:30 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

void	ft_exit(t_minishell *g_minishell)
{
	g_minishell->re = 0;
	ft_putstr_fd("exit\n", 2);
	if (g_minishell->tokens[1].str == NULL)
		exit(0);
	else if (g_minishell->tokens[2].str == NULL)
	{
		if (!ft_is_numeric(g_minishell->tokens[1].str))
		{
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(g_minishell->tokens[1].str, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(2);
		}
		else
			exit(ft_atoi(g_minishell->tokens[1].str));
	}
	else
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		exit(1);
		return;
	}
	exit(0);
	return;
}
