/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:42:56 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/13 16:15:56 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_identifier_exp(char *str)
{
	int	i;

	i = -1;
	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (printf("minishell: 1: Syntax error: \"%s\" unexpected\n", str));
	while (str[++i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_' && str[i] != '=')
			return (printf("minishell: 1: Syntax error: \"%s\" unexpected\n", str));
	}
	return (0);
}

void	ft_export(t_minishell *minishell, t_tokens *tokens)
{
	minishell->re = 0;
	if (tokens[1].str == NULL)
		return ;
	if (ft_strchr(tokens[1].str, '='))
	{
		if (is_identifier_exp(tokens[1].str))
		{
				minishell->re = 1;
				return ;
		}
		ft_lstadd_back(minishell->envlst, ft_lstnew(get_name(tokens[1].str), get_value(tokens[1].str)));
		printf("export %s\n", tokens[1].str);
	}
	return ;
}
