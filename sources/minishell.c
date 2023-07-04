/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:40:19 by biaroun           #+#    #+#             */
/*   Updated: 2023/07/04 17:14:14 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_token(t_tokens *token)
{
	int i = -1;
	while(token[++i].str)
		printf("mot[%d] = %s\n", i, token[i].str);
	printf("mot[%d] = %s\n", i, token[i].str);
}

void	free_tokens(t_tokens *tokens)
{
	int i = -1;
	while (tokens[++i].str)
		free(tokens[i].str);
	free(tokens);
}

void	shell(t_minishell *g_minishell)
{
	char			*str;
	t_tokens		*tokens;

	tokens = NULL;
	//init_signal();
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
		{
			ft_putstr_fd("exit\n", 2);
			exit(0);
		}
		if (str == NULL || str[0] == '\0')
			continue ;
		add_history(str);
		if (err_unclosed_quote(str))
			continue ;
		g_minishell->tokens = ft_lexer(str);//a revoir
		//print_token(g_minishell->tokens);
		find_cmd(g_minishell, 0);
		free_tokens(g_minishell->tokens);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_env		envlst;
	t_minishell	g_minishell;

	(void) ac;
	(void) av;
	get_envlst(envp, &envlst);
	init_minishell(&g_minishell, envlst.next);
	shell(&g_minishell);
	return (0);
}
