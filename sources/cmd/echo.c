/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:56:05 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/30 10:49:04 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_minishell *g_minishell)
{
	g_minishell->re = 0;
	return ;
}
/*int	file_exists(t_minishell *mini, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		ft_echo(mini, 1);
		return (1);
	}
	return (0);
}

void	echo_create(t_minishell *mini, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("open");
		ft_echo(mini, 1);
		exit(EXIT_FAILURE);
	}
	wr = write(fd, &mini->token->str, strlen(mini->token->str));
	if (wr == -1)
	{
		perror("write");
		ft_echo(mini, 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	append_to_file(t_minishell *mini, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("open");
		ft_echo(mini, 1);
		exit(EXIT_FAILURE);
	}
	wr = write(fd, &mini->token->str, strlen(mini->token->str));
	if (wr == -1)
	{
		perror("write");
		ft_echo(mini, 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	replace_file_content(t_minishell *mini, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		perror("open");
		ft_echo(mini, 1);
		exit(EXIT_FAILURE);
	}
	wr = write(fd, mini->token->str, strlen(mini->token->str));
	if (wr == -1)
	{
		perror("write");
		ft_echo(mini, 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	manager(t_minishell *mini, char *filename, int roa)
{
	int	fd;

	fd = file_exists(t_minishell *mini, filename);
	if (fd == 0)
		echo_create(mini->token->str, filename);
	else
	{
		if (roa == 1)
			append_to_file(mini->token->str, filename);
		if (roa == 0)
			replace_file_content(content->str, filename);
	}
	ft_echo(mini, 0);
}*/
