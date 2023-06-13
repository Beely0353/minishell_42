/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:43:04 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/13 15:56:23 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_identifier(char *str)
{
	int	i;

	i = -1;
	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (printf("minishell: unset: `%s': not a valid identifier\n", str));
	while (str[++i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (printf("minishell: unset: `%s': not a valid identifier\n", str));
	}
	return (0);
}

void remove_var(t_minishell *minishell, char *str)
{
	t_env	*tmp;
	t_env	*tmp2;
	
	tmp = minishell->envlst;
	tmp2 = tmp;

	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
		{
			if (tmp == minishell->envlst)
				minishell->envlst = tmp->next;
			else
				tmp2->next = tmp->next;
			free(tmp->name);
			free(tmp->value);
			free(tmp);
			return ;
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
}


void	ft_unset(t_minishell *minishell, t_tokens *tokens)
{
	int	i;

	i = 0;
	minishell->re = 0;
	while (tokens[++i].str)
	{
		if (is_identifier(tokens[i].str))
		{
			minishell->re = 1;
			return ;
		}
	}
	i = 0;
	while (tokens[++i].str)
		remove_var(minishell, tokens[i].str);
	return ;
}
