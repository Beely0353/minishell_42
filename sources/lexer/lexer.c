/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:44:19 by biaroun           #+#    #+#             */
/*   Updated: 2023/07/04 17:04:46 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sepcpy(char *arg, t_tokens *tokens, int *i)
{
	char	*d;
	int		j;

	j = 2;
	if (arg[*i] == arg[*i + 1])
		j++;
	d = malloc(sizeof(char) * 2);
	d[0] = arg[*i];
	d[1] = arg[*i + 1];
	if (arg[*i] == arg[*i + 1])
	{
		d[2] = '\0';
		(*i)++;
	}
	else
		d[1] = '\0';
	tokens->str = d;
}

void	ft_argcpy(char *args, int *i, t_tokens *tokens)
{
	char	*arg;
	int		j;

	j = *i;
	tokens->spcecho = 1;
	if (ft_isspcable(args[*i - 1]))
		tokens->spcecho = 0;
	while (args[j] && !ft_issep(args[j]) && !ft_isspace(args[j]))
		j++;
	arg = malloc(sizeof(char) * j - *i + 1);
	j = 0;
	while (args[*i] && !ft_isspace(args[*i]) && !ft_issep(args[*i]))
		arg[j++] = args[(*i)++];
	arg[j] = '\0';
	(*i)--;
	tokens->str = arg;
}

char	*ft_voidquote(char c)
{
	char	*new;

	new = malloc(sizeof(char) * 3);
	new[0] = c;
	new[1] = c;
	new[2] = '\0';
	return (new);
}

void	ft_quotecpy(char *args, int *i, t_tokens *tokens)
{
	char	*new;
	int		j;
	char	quote;

	j = *i;
	tokens->spcecho = 1;
	if (ft_isspcable(args[*i - 1]))
		tokens->spcecho = 0;
	quote = args[(*i)++];
	if (args[(*i)] == quote)
		tokens->str = ft_voidquote(quote);
	if (args[(*i)] == quote)
		return ;
	while (args[j] && args[j + 1] != quote)
		j++;
	new = malloc(sizeof(char) * j - *i + 4);
	j = 0;
	new[j++] = quote;
	while (args[*i] && args[(*i) + 1] != quote)
		new[j++] = args[(*i)++];
	new[j++] = args[(*i)++];
	new[j++] = quote;
	new[j] = '\0';
	tokens->str = new;
}

t_tokens	*ft_lexer(char *args)
{
	t_tokens	*tokens;
	int			i;
	int			j;

	i = -1;
	j = 0;
	tokens = malloc(sizeof(t_tokens) * ft_cptword(args));
	while (args[++i])
	{
		if (ft_isquote(args[i]))
			ft_quotecpy(args, &i, &tokens[j++]);
		else if (ft_isfle(args[i]))
			ft_sepcpy(args, &tokens[j++], &i);
		else if (!ft_isspace(args[i]))
			ft_argcpy(args, &i, &tokens[j++]);
	}
	tokens[0].spcecho = 1;
	tokens[j].str = NULL;
	tokens = join_quotes(tokens);
	return (tokens);
}
