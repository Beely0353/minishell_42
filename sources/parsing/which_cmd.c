/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:12:32 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/22 10:24:42 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	which_cmd(t_minishell *minishell, char *cmd)
{
	int	i;

	i = 0;
	while (minishell->builtins[i])
	{
		if (!ft_strcmp(minishell->builtins[i], cmd))
			break ;
		i++;
	}
	if (i == 9)
	{
		printf("minishell: %s: command not found\n", cmd);
		return (-1);
	}
	return (i);
}

int	find_cmd(t_minishell *minishell, int cmd)
{
	int	which;

	which = which_cmd(minishell, minishell->tokens[cmd].str);
	if (which == -1)
		return (1);
	else if (which == 0)
		ft_echo(minishell, minishell->tokens);
	else if (which == 1)
		ft_cd(minishell, minishell->tokens);
	else if (which == 2)
		ft_pwd(minishell);
	else if (which == 3)
		ft_export(minishell, minishell->tokens);
	else if (which == 4)
		ft_unset(minishell, minishell->tokens);
	else if (which == 5)
		ft_env(minishell->envlst, minishell);
	else if (which == 6)
		ft_exit(minishell);
	else if (which == 7)
		ft_clear(minishell);
	else if (which == 8)
		ft_history(minishell);
	return (0);
}
