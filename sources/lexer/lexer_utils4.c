/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:09:10 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/30 10:42:28 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_whitout_q(char *str)
{
	int	i;
	int	j;
	int	b;
	char	c;

	i = -1;
	j = 0;
	b = 0;
	while (str[++i])
	{
		if (ft_isquote(str[i]) && !b)
		{
			c = str[i];
			b = 1;
			j++;
		}
		if (str[i] == c && b)
		{	
			b = 0;
			j++;
		}
	}
	return (i - j);
}
char	*r_quote(char *str)
{
	int	i;
	char	*new;
	int	j;
	char	c;
	int	b;

	i = -1;
	j = 0;
	new = malloc(sizeof(char) * (i - j + 1));
	while (str[++i])
	{
		if (ft_isquote(str[i]) && !b)
		{
			c = str[i];
			b = 1;
			continue ;
		}
		if (str[i] == c && b)
		{	
			b = 0;
			continue ;
		}
		new[j++] = str[i];
	}
	new[j] = '\0';
	return (new);
}

t_tokens	*remove_quotes(t_tokens *tokens)
{
	int	i;
	int	j;
	t_tokens	*new;
	
	i = -1;
	j = 0;
	while (tokens[j].str)
			j++;
	new = malloc(sizeof(t_tokens) * (j + 1));
	j = 0;
	while (tokens[++i].str)
	{
		if (ft_strchr(tokens[i].str, '\'') || ft_strchr(tokens[i].str, '"'))
			new[j++].str = r_quote(tokens[i].str);
		else
			new[j++].str = ft_strdup(tokens[i].str);
	}
	free_tokens(tokens);
	return (new);
}