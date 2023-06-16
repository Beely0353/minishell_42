/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychirouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:09:05 by ychirouz          #+#    #+#             */
/*   Updated: 2023/06/16 13:53:21 by ychirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

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

void	echo_create(char *content, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	wr = write(fd, content, strlen(content));
	if (wr == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	append_to_file(char *content, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	wr = write(fd, content, strlen(content));
	if (wr == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	replace_file_content(char *content, char *filename)
{
	int	fd;
	int	wr;

	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	wr = write(fd, content, strlen(content));
	if (wr == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	manager(char *content, char *filename, int roa)
{
	int	fd;

	fd = file_exists(filename);
	if (fd == 0)
		echo_create(content, filename);
	else
	{
		if (roa == 1)
			append_to_file(content, filename);
		if (roa == 0)
			replace_file_content(content, filename);
	}
}
