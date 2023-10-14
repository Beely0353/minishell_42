/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:09:10 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/19 02:59:18 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*r_quote(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 1;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) - 1));
	while (str[i + 1])
		new[j++] = str[i++];
	new[j] = '\0';
	printf("str = %s\n", new);
	return (new);
}

t_tokens	*remove_quotes(t_tokens *tokens)
{
	int			i;
	int			j;
	t_tokens	*new;

	i = -1;
	j = 0;
	while (tokens[j].str != NULL)
		j++;
	new = malloc(sizeof(t_tokens) * (j + 1));
	j = 0;
	while (tokens[++i].str)
	{
		new[j].path_cmd = NULL;
		new[j].dquote = 1;
		if (tokens[i].str[0] == '\'' || tokens[i].str[0] == '"')
			new[j++].str = r_quote(tokens[i].str);
		else
			new[j++].str = ft_strdup(tokens[i].str);
	}
	new[j].path_cmd = NULL;
	new[j].str = NULL;
	new[j].type = 0;
	free_tokens(tokens);
	return (new);
}

int	dquote_or_squote(char quote)
{
	if (quote == '\"')
		return (1);
	return (0);
}
