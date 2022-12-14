/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:56:22 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 18:54:46 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmdcmp(char *s1, char **s2)
{
	int	i;

	i = -1;
	while (s2[++i])
	{
		if (ft_strcmp(s1, s2[i]) == 0)
			return (1);
	}
	return (0);
}
