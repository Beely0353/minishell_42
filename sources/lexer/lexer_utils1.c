/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:44:59 by biaroun           #+#    #+#             */
/*   Updated: 2023/08/26 17:38:02 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int		j;
	char	c;

	j = *i;
	c = args[*i];
	j++;
	while (args[j] && args[j] != c)
		j++;
	*i = j;
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

	i = 0;
	j = 0;
	while (args[i])
	{
		if (ft_isquote(args[i]))
			j += ft_cptquote(args, &i);
		else if (ft_isfle(args[i]))
			j += ft_cptarrow(args, &i);
		else if (!ft_isspace(args[i]) && args[i] != '\0')
			j += ft_cptarg(args, &i);
		if (args[i] == '\0')
			break ;
		i++;
	}
	return (j + 1);
}
