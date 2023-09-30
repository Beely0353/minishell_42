/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:11:26 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/19 02:34:22 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_token(t_tokens *tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens[i].str != NULL)
	{
		if (tokens[i].str == NULL)
			break ;
		if (tokens[i].spcecho == 1 && tokens[i + 1].str && tokens[i + 1].spcecho == 0)
		{
			i++;
			j++;
			while (tokens[i].spcecho == 0 && tokens[i].str != NULL)
				i++;
			continue ;
		}
		else
			j++;
		i++;
	}
	return (j);
}

char	*quotejoin(t_tokens *token, int k, int i)
{
	int	tmp;
	int	j;
	char	*str;
	
	tmp = k;
	j = 0;
	while (tmp != i)
		j += ft_strlen(token[tmp++].str) - 2;
	str = malloc(sizeof(char) * j + 1);
	return (str);
}


char	*join_tokens(t_tokens *tokens, int *k)
{
	int	j;
	int	i;
	char	*str;
	
	j = *k;
	i = *k;
	i++;
	while (tokens[i].spcecho == 0 && tokens[i].str != NULL)
		i++;
	str = tokens[j++].str;
	while (j != i)
		str = ft_strjoin(str, tokens[j++].str);
	*k = j;
	return (str);
}

t_tokens	*join_quotes(t_tokens *tokens)
{
	int	i;
	int	j;
	t_tokens	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(t_tokens) * (count_token(tokens) + 1));
	while (tokens[i].str != NULL)
	{
		if (tokens[i].spcecho == 3)
			new[j++].str = tokens[i].str;
		else if (tokens[i].spcecho == 1 && tokens[i + 1].str && tokens[i + 1].spcecho == 0)
		{
			new[j++].str = join_tokens(tokens, &i);
			continue ;
		}
		else
			new[j++] = tokens[i];
		if (tokens[i].str == NULL)
			break ;
		i++;
	}
	new[j].str = NULL;
	free(tokens);
	return (remove_quotes(new));
}
