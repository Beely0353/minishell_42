/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:48:20 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/06 15:23:59 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstlast(t_env	*lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_env *alst, t_env *n)
{
	if (!alst || !n)
		return ;
	n->next = alst;
	alst = n;
}

void	ft_lstadd_back(t_env *alst, t_env *n)
{
	t_env	*last;

	if (alst)
	{
		last = ft_lstlast(alst);
		last->next = n;
	}
	else
		alst = n;
}

t_env	*ft_lstnew(char *name, char *value)
{
	t_env	*dst;

	dst = malloc(sizeof(t_env));
	if (!dst)
		return (NULL);
	dst->next = NULL;
	dst->name = name;
	dst->value = value;
	return (dst);
}
