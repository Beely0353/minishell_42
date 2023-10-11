/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 04:17:34 by biaroun           #+#    #+#             */
/*   Updated: 2023/08/25 04:17:55 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirect(char *token)
{
	return (ft_strcmp(token, "<") == 0 || ft_strcmp(token, ">") == 0
		|| ft_strcmp(token, ">>") == 0 || ft_strcmp(token, "<<") == 0
		|| ft_strcmp(token, "|") == 0);
}
char	*ft_rmv_path(char *str)
{
	int	i;
	int	j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (str[i] != '/')
	{
		i--;
		j++;
	}
	i++;
	new = malloc(sizeof(char) * (j));
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

int	cmd_abs_exists(t_tokens *token)
{
	if (access(token->str, X_OK) == 0)
	{
		if (ft_strlen(token->str) > 0)
		{
			token->path_cmd = ft_strdup(token->str);
			free(token->str);
			token->str = ft_rmv_path(token->path_cmd);
			return (1);
		}
	}
	return (0);
}