/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:12:32 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/08 12:14:41 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	which_cmd(t_minishell *g_minishell, char *cmd)
{
	int	i;

	i = 0;
	while (g_minishell->builtins[i])
	{
		if (!ft_strcmp(g_minishell->builtins[i], cmd))
			break ;
		i++;
	}
	if (i == 9)
	{
		ft_putstr_fd("sh: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		return (-1);
	}
	return (i);
}

int	find_cmd(t_minishell *g_minishell, char **cmd)
{
	int	which;

	which = which_cmd(g_minishell, cmd[0]);
	if (which == -1)
		return (1);
	else if (which == 0)
		ft_echo(g_minishell);
	else if (which == 1)
		ft_cd(g_minishell);
	else if (which == 2)
		ft_pwd(g_minishell);
	else if (which == 3)
		ft_export(g_minishell);
	else if (which == 4)
		ft_unset(g_minishell);
	else if (which == 5)
		ft_env(g_minishell->envlst, g_minishell);
	else if (which == 6)
		ft_exit(g_minishell);
	else if (which == 7)
		ft_clear(g_minishell);
	else if (which == 8)
		ft_history(g_minishell);
	return (0);
}
