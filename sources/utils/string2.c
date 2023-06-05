/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:21:01 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/05 17:21:02 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	count_strs(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
		}
		else
		{
			i++;
			while (*s != '\0' && *s != c)
			{
				s++;
			}
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int			len;
	int			i;
	const char	*start;
	char		**array;

	array = (char **) malloc(((count_strs(s, c)) + 1) * sizeof(*array));
	if (!array)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (*(s - 1) != c)
			array[i++] = ft_substr(start, 0, len);
	}
	array[i] = 0;
	return (array);
}
