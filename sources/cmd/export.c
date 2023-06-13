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
		return (printf("minishell: unset: `%s': not a valid identifier\n", str));
	while (str[++i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_' && str[i] != '=')
			return (printf("minishell: unset: `%s': not a valid identifier\n", str));
	}
	return (0);
}

void	ft_export(t_minishell *minishell, t_tokens *tokens)
{
	int	i;

	i = 0;
	minishell->re = 0;
	while (tokens[++i].str)
	{
		if (is_identifier_exp(tokens[i].str))
		{
			minishell->re = 1;
			return ;
		}
	}
	i = 0;
	while (tokens[++i].str)
	{
		if (ft_strchr(tokens[i].str, '='))
					ft_lstadd_back(minishell->envlst, ft_lstnew(get_name(tokens[i].str), get_value(tokens[i].str)));
	}
	return ;
}
