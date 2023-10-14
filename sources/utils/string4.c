/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:11:42 by biaroun           #+#    #+#             */
/*   Updated: 2023/08/31 09:10:14 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (s[i] == c)
		return (s + i);
	return (NULL);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (sign * result);
}

char	*ft_strcpy(char *dest, const char *src)
{

    char *original_dest = dest;

    while ((*src))
		*dest++ = *src++;
    return (original_dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
    char *original_dest = dest;

    while (n > 0 && (*dest++ = *src++)) 
	{
        n--;
    }
    while (n > 0) 
	{
        *dest++ = '\0';
        n--;
    }
    return (original_dest);
}

char *ft_strstr(const char *haystack, const char *needle)
{
	const char *h;
	const char *n;

    while (*haystack != '\0') 
	{
		h = haystack;
		n = needle;
        while (*n != '\0' && *h == *n) 
		{
            h++;
            n++;
        }
        if (*n == '\0')
		{
            return (char *)haystack;
        }
        haystack++;
    }
    return (NULL);
}
