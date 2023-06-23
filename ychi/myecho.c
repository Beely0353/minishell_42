/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:09:05 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/23 16:09:54 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

//-----------------ECHO TERM----------------//

int	echo_term(t_token *token, int n, const char *file)
{
	int	i;
	i = 0;
	while (token->str[i])
	{
		if ((token->str[i] == '\n' && token->str[i + 1] == 0x00) && n == 1)
			return (0);
		write(1, &token->str[i], 1);
		i++;
	}
	return (0);
}


//--------------------ECHO PIPE--------------//

int	file_exists(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

void	echo_create(t_token *content, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	wr = write(fd, content->str, strlen(content));
	if (wr == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	append_to_file(t_token *content, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	wr = write(fd, content->str, strlen(content));
	if (wr == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	replace_file_content(t_token *content, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	wr = write(fd, content->str, strlen(content));
	if (wr == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	manager(t_token *content, char *filename, int roa)
{
	int	fd;

	fd = file_exists(filename);
	if (fd == 0)
		echo_create(content->str, filename);
	else
	{
		if (roa == 1)
			append_to_file(content->str, filename);
		if (roa == 0)
			replace_file_content(content->str, filename);
	}
}
