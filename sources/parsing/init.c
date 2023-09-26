/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:25:58 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/26 12:56:51 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(t_minishell *g_minishell, t_env *envlst)
{
	g_minishell->re = 0;
	g_minishell->builtins = malloc(sizeof(char *) * 10);
	g_minishell->builtins[0] = "echo";
	g_minishell->builtins[1] = "cd";
	g_minishell->builtins[2] = "pwd";
	g_minishell->builtins[3] = "export";
	g_minishell->builtins[4] = "unset";
	g_minishell->builtins[5] = "env";
	g_minishell->builtins[6] = "exit";
	g_minishell->builtins[7] = "clear";
	g_minishell->builtins[8] = "history";
	g_minishell->builtins[9] = NULL;
	g_minishell->envlst = envlst;
	g_minishell->PATH = ft_split(get_env_value("PATH", envlst), ':');
}
