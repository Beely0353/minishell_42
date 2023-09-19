/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:05:18 by biaroun           #+#    #+#             */
/*   Updated: 2023/08/31 08:16:41 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(char *token)
{
	return (ft_strcmp(token, "<") == 0 || ft_strcmp(token, ">") == 0
		|| ft_strcmp(token, ">>") == 0 || ft_strcmp(token, "<<") == 0
		|| ft_strcmp(token, "|") == 0);
}

int	cmd_exists(t_tokens *token, t_minishell *mini)
{
	char	**path;
	char	*full_path;

	if (token->str[0] == '/' || token->str[0] == '.')
		return (1);
	if (get_env_value("PATH", mini->envlst) == NULL)
		return (0);
	path = ft_split(get_env_value("PATH", mini->envlst), ':');
	while (path && *path)
	{
		full_path = ft_strjoin(*path, "/");
		full_path = ft_strjoin(full_path, token->str);
		if (access(full_path, X_OK) == 0)
		{
			if (ft_strlen(token->str) > 0)
			{
				token->str = ft_strdup(full_path);
				free(full_path);
				return (1);
			}
		}
		free(full_path);
		path++;
	}
	return (0);
}//refaire

void    parse_redir_token(t_tokens *tokens, int i)
{
    if (ft_strcmp(tokens[i].str, ">>") == 0)
		tokens[i].REDIR_type = 1;
	else if (ft_strcmp(tokens[i].str, "<<") == 0)
		tokens[i].REDIR_type = 2;
	else if (ft_strcmp(tokens[i].str, "<") == 0)
		tokens[i].REDIR_type = 3;
	else if (ft_strcmp(tokens[i].str, ">") == 0)
		tokens[i].REDIR_type = 4;
	else if (ft_strcmp(tokens[i].str, "|") == 0)
		tokens[i].REDIR_type = 5;
}

int	is_builtins(t_minishell *minishell, char *cmd)
{
	int	i;

	i = 0;
	while (minishell->builtins[i])
	{
		if (!ft_strcmp(minishell->builtins[i], cmd))
			break ;
		i++;
	}
    if (i == 9)
        return (0);
	return (1);

}

void	parse_tokens(t_tokens *tokens, t_minishell *mini)
{
	size_t	i;

	i = 0;
	while (tokens[i].str != NULL)
	{   
		tokens[i].type = 5;
		if (is_redir(tokens[i].str))
        {
            tokens[i].type = 1;
			parse_redir_token(tokens, i);
        }
        else if (is_builtins(mini, tokens[i].str))
            tokens[i].type = 2;
        else if (cmd_exists(tokens + i, mini))
            tokens[i].type = 3;
        else
            tokens[i].type = 4;
		i++;
	}
}