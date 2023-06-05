/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:44:38 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/05 16:44:45 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r');
}

int	ft_isspcable(int c)
{
	if (ft_isspace(c) || ft_isfle(c))
		return (0);
	else
		return (1);
}

int	ft_issep(int c)
{
	return (ft_isfle(c) || ft_isquote(c));
}

int	ft_isquote(int c)
{
	return (c == '\"' || c == '\'');
}

int	ft_isfle(int c)
{
	return (c == '>' || c == '<' || c == '|');
}
