/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mypipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:13:06 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/26 17:17:58 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	end_pipe(int *pipefd, char **command1, char **command2, int pid1o2)
{
	if (pid == 1)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execvp(command1[0], command1);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	if (pid == 2)
	{
		dup2(pipefd[0], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execvp(command1[0], command1);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
}

void	ft_pipe(char **command1, char **command2)
{
	int		pipefd[2];
	int		pipe;
	pid_t	pid1;
	pid_t	pid2;

	pipe = pipe(pipefd);
	if (pipe == -1)
		pideror();
	pid1 = fork();
	if (pid1 == -1)
		pideror();
	if (pid1 == 0)
		end_pipe(pipefd, command1, command2, 1);
	pid2 = fork();
	if (pid2 == -1)
		pideror();
	if (pid2 == 0)
		end_pipe(pipefd, command1, command2, 2);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	nbr_builtins(t_minishell *mini)
{
	int	i;

	i = 0;
	while (mini->builtins[i])
		i++;
	return (i);
}

int	**verif_cmd(t_minishell *mini)
{
	int	**re;

	re = malloc(sizeof(int *) * nbr_builtins(mini));
	j = 0;
	i = 0;
	r = 0;
	verif_cmd2(mini, re);
	return (re);
}

void	verif_cmd2(t_minishell *mini, int **re)
{
	int	i;
	int	j;
	int	r;
	int	g;

	i = 0;
	j = 0;
	r = 0;
	while (mini->builtins[i])
	{
		g = ft_isalpha(mini->builtins[i][0]);
		if (g == 1)
		{
			while (mini->bin[j])
			{
				if (mini->builtins[i] == mini->bin[j])
					re[r++] = 1;
				else
					re[r++] = 0;
				j++;
			}
		}
		i++;
	}
	re[r] = 0x00;
}
