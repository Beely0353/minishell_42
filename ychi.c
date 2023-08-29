
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ychi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:00:29 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/08 16:03:56 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_pipe_fork(t_minishell minishell)
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
			minishell.re = exit_status;
		}
		else if (WIFSIGNALED(status))
		{
			signal_number = WTERMSIG(status);
			minishell.re = signal_number;
		}
		pid = wait(&status);
	}
}

void	ft_pwd(void)
{
	char	path[4096];

	if (getcwd(path, sizeof(path)))
		printf("%s\n", path);
	else
		printf("shit\n");
}