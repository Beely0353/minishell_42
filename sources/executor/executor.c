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

char	**get_cmd_arg(t_tokens *tokens, int *j)
{
	char **arg;
	int counter;
	int tmp;
	
	counter = 0;
	tmp = *j;
	while(tokens[++(*j)].type == 4)
		counter++;
	*j = tmp;
	tmp = 0;
	arg = malloc(sizeof(char*) * counter + 1);
	if (!arg)
		return (NULL);
	counter += 1;
	while(counter--)
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
		printf("erreur fork");
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

int	ft_executor(t_minishell *g_minishell,t_tokens *tokens)
{
	int		i;
	int 	j;
	char 	**arg;
	//int tmp;
	
	//tmp = -1;
	g_minishell->re = 0;
	i = -1;
	//arg = NULL;
	while(tokens[++i].str)
	{
		if(tokens[i].type == 3)
		{
			j = i;
			arg = get_cmd_arg(tokens, &j);
			/*printf("cmd = %s\n",tokens[i].path_cmd);
			printf("opt1 = %s\n",arg[0]);
			printf("opt2 = %s\n",arg[1]);*/
			exec_cmd(tokens[i].path_cmd, arg);
			free(tokens[i].path_cmd);
			i = j;
			free(arg);//a corriger
			/*while(tokens[++tmp].type)
				printf("%p\n", tokens[tmp].type);
			printf("%p\n", tokens->type);*/
			
		}
	}
	return(EXIT_SUCCESS);
}
