/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:40:19 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/05 18:09:29 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_token(t_tokens *token)
{
	int i = -1;
	while(token[++i].str)
		printf("mot[%d] = %s\n", i, token[i].str);
}
void	shell(void)
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
		tokens = ft_lexer(str);
		print_token(tokens);
	}
}
int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	(void) env;
	shell();
	return (0);
}
