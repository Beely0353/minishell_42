/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 02:50:29 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/26 12:56:52 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_path(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
    str[i++] = '/';
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	count_nbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
	}
	if (!n)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*dst;
	int			i;
	long int	nbr;

	i = count_nbr(n);
	dst = malloc(i * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		dst[0] = '-';
	}
	dst[i--] = '\0';
	if (n == 0)
		dst[i] = '0';
	while (nbr)
	{
		dst[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	return (dst);
}

int	ft_random(void)
{
	int	fd;
	int	random_number;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (42);
	read(fd, &random_number, sizeof(int));
	close(fd);
	if (random_number < 0)
		random_number *= -1;
	return (random_number);
}