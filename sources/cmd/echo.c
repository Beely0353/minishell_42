/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:56:05 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/22 10:38:29 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_n(t_tokens *tokens)
{
	int	i;

	i = -1;
	if (tokens[0].str)
	{
		while (tokens[++i].type == 4)
		{
			printf("%s", tokens[i].str);
			if (tokens[i + 1].type == 4)
				printf(" ");
		}
	}
}

void	ft_echo(t_minishell *g_minishell, t_tokens *tokens)
{
	int	i;

	i = 1;
	g_minishell->re = 0;
	if (tokens[i].str)
	{
		if (!ft_strcmp(tokens[1].str, "-n"))
		{
			ft_echo_n(tokens + 2);
			return ;
		}
		while (tokens[i].type == 4)
		{
			printf("%s", tokens[i].str);
			if (tokens[i + 1].type == 4)
			printf(" ");
			i++;
		}
	}
	printf("\n");
}
