/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:00:21 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 18:56:58 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**tokentostr(t_tokens *token)
{
	int		i;
	char	**new;

	i = 0;
	while (token[i].str != NULL)
		i++;
	new = malloc(sizeof(char *) * i + 1);
	i = -1;
	while (token[++i].str != NULL)
		new[i] = token[i].str;
	new[i] = NULL;
	return (new);
}

int	ft_cptquote(char *args, int *i)
{
	char	quote;

	quote = args[(*i)++];
	while (args[*i] && args[*i] != quote)
		(*i)++;
	return (1);
}

int	ft_cptarg(char *args, int *i)
{
	while (args[*i] && !ft_isspace(args[*i]) && !ft_issep(args[*i]))
		(*i)++;
	(*i)--;
	return (1);
}

int	ft_cptarrow(char *args, int *i)
{
	if (args[*i] == args[*i + 1])
		(*i)++;
	return (1);
}

size_t	ft_cptword(char *args)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (args[++i])
	{
		if (ft_isquote(args[i]))
			j += ft_cptquote(args, &i);
		else if (ft_isfle(args[i]))
			j += ft_cptarrow(args, &i);
		else if (!ft_isspace(args[i]))
			j += ft_cptarg(args, &i);
	}
	return (j + 1);
}
