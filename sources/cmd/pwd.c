/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:42:45 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/13 15:11:08 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_fork(t_minishell *minishell)
{
	int		exit_status;
	int		status;
	int		signal_number;
	pid_t	pid;

	pid = wait(&status);
	while (pid != -1)
	{
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			minishell->re = exit_status;
		}
		else if (WIFSIGNALED(status))
		{
			signal_number = WTERMSIG(status);
			minishell->re = signal_number;
		}
		pid = wait(&status);
	}
}

void	ft_pwd(t_minishell *minishell)
{
	char	path[4096];

	minishell->re = 0;
	if (getcwd(path, sizeof(path)))
		printf("%s\n", path);
	else
		printf("shit\n");
}
