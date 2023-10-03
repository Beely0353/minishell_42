/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:40:08 by nihamdan          #+#    #+#             */
/*   Updated: 2023/09/26 10:58:4 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(t_minishell *g_minishell, t_tokens *tokens)
{
	/*int ret;

	ret = 0;*/
	if(ft_strcmp(tokens->str,"echo") == 0)
		ft_echo(g_minishell, tokens);
	else if(ft_strcmp(tokens->str,"cd") == 0)
		ft_cd(g_minishell, tokens);
	else if(ft_strcmp(tokens->str,"pwd") == 0)
		ft_pwd(g_minishell);
	else if(ft_strcmp(tokens->str,"export") == 0)
		ft_export(g_minishell, tokens);
	else if(ft_strcmp(tokens->str,"unset") == 0)
		ft_unset(g_minishell, tokens);
	else if(ft_strcmp(tokens->str,"env") == 0)
		ft_env(g_minishell->envlst, g_minishell);
	else if(ft_strcmp(tokens->str,"exit") == 0)
		ft_exit(g_minishell);
	/*if (ret == 0)
		return(EXIT_SUCCESS);*/
	return(EXIT_SUCCESS);
}

char	**get_cmd_arg(t_tokens *tokens, int *j)
{
	char **arg;
	int counter;
	int tmp;

	counter = 1;
	tmp = *j;
	(*j)++;
	while(tokens[(*j)++].type == 4)
		counter++;
	*j = tmp;
	tmp = 0;
	arg = malloc(sizeof(char*) * (counter + 1));
	if (!arg)
		return (NULL);
	while(counter-- && tokens[(*j)].str)
		arg[tmp++] = tokens[(*j)++].str;
	arg[tmp] = NULL;
	return (arg);
}

int exec_cmd(char *cmd, char **arg)
{
	pid_t 	pid;
	int		status;

	pid = fork();
	if(pid == -1)
	{
		perror("Erreur fork ");
		return(EXIT_FAILURE);
	}
	else if(pid > 0)
		wait(&status);
	else
	{
		if(execve(cmd, arg, NULL) == -1)
			perror("Erreur cmd ");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	exec_builtin(t_minishell *g_minishell, t_tokens *tokens)
{
	pid_t 	pid;
	int		status;

	pid = fork();
	if(pid == -1)
	{
		perror("Erreur fork ");
		return(EXIT_FAILURE);
	}
	else if(pid > 0)
		wait(&status);
	else
	{
		if(builtin(g_minishell, tokens) == 1)
			perror("Erreur cmd ");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_executor(t_minishell *g_minishell,t_tokens *tokens)
{
	int		i;
	int 	j;
	char 	**arg;

	g_minishell->re = 0;
	i = 0;
	arg = NULL;
	while(tokens[i].str)
	{
		if(tokens[i].type == 2 || tokens[i].type == 3)
		{
			j = i;
			arg = get_cmd_arg(tokens, &j);
			if (tokens[i].type == 3)
				exec_cmd(tokens[i].path_cmd, arg);
			else
				exec_builtin(g_minishell, &tokens[i]);
			i = j;
			free(arg);
		}
		if (tokens[i].type == 1)//a modifier
			i++;
	}
	return(EXIT_SUCCESS);
}
