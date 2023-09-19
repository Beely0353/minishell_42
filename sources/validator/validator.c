/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 04:42:56 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/19 02:11:10 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int first_is_cmd(t_tokens tokens)
{
    if (tokens.type == 2 || tokens.type == 3 )
        return (0);
    ft_putstr_fd("minishell: ", STDOUT_FILENO);
    ft_putstr_fd(tokens.str, STDOUT_FILENO);
    ft_putstr_fd(": command not found\n", STDOUT_FILENO);
    return (1);
}

int no_consecutive_redir(t_tokens *tokens)
{
    int i;

    i = -1;
    while(tokens[++i].str)
    {
        if (tokens[i].type == 1 && tokens[i + 1].type == 1)
        {
            ft_putstr_fd("minishell: syntax error near unexpected token `", STDOUT_FILENO);
            ft_putstr_fd(tokens[i + 1].str, STDOUT_FILENO);
            ft_putstr_fd("`\n", STDOUT_FILENO);
            return (1);
        }

    }
    return (0);
}

int command_not_found(t_tokens *tokens)
{
    int i;

    i = -1;
    while(tokens[++i].str)
    {
        if (tokens[i].type == 5)
        {
            ft_putstr_fd("minishell: ", STDOUT_FILENO);
            ft_putstr_fd(tokens[i].str, STDOUT_FILENO);
            ft_putstr_fd(": command not found\n", STDOUT_FILENO);
            return (1);
        }
    }
    return (0);
}

int no_cmd_after_pipe(t_tokens *tokens)
{
    int i;

    i = -1;
    while(tokens[++i].str)
    {
        if (tokens[i].type == 1 && tokens[i].REDIR_type == 5)
        {
            if (tokens[i + 1].type != 2 && tokens[i + 1].type != 3)
            {
                ft_putstr_fd("minishell: ", STDOUT_FILENO);
                ft_putstr_fd(tokens[i + 1].str, STDOUT_FILENO);
                ft_putstr_fd(": command not found\n", STDOUT_FILENO);
                return (1);
            }
        }
    }
    return (0);
}

int	ft_validator(t_tokens *tokens)
{
    if (no_consecutive_redir(tokens))
        return (0);
    if (first_is_cmd(tokens[0]))
        return (0);
    if (command_not_found(tokens))
        return (0);
    if (no_cmd_after_pipe(tokens))
        return (0);
    return (1);
}