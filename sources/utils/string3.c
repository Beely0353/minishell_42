/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:22:09 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/05 18:06:43 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *str, int fd)
{
	write (fd, str, ft_strlen(str) - 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = *(s + start + i);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dst = malloc(len * sizeof(char));
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, len);
	return (dst);
}
