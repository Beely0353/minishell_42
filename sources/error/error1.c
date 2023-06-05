/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:51:18 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/05 16:51:31 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	err_unclosed_quote(char *str)
{
	int	i;
	int	quote;
	int	dquote;

	i = -1;
	quote = 0;
	dquote = 0;
	while (str[++i])
	{
		if (str[i] == '\'' && dquote % 2 == 0)
			quote++;
		if (str[i] == '\"' && quote % 2 == 0)
			dquote++;
	}
	if (quote % 2 == 1 || dquote % 2 == 1)
	{
		write(2, "minishell: syntax error unclosed quote\n", 39);
		return (1);
	}
	return (0);
}
