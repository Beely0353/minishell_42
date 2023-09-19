/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:42:45 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/16 15:46:33 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_minishell *minishell)
{
	char	path[4096];

	minishell->re = 0;
	if (getcwd(path, sizeof(path)))
		printf("%s\n", path);
	else
		printf("shit\n");
}
