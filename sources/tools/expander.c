/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:25:52 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/29 05:03:07 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remplace_expand_short(char *str, char *name, int *k, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (str[*i] != '$')
		(*i)++;
	*k = ++(*i);
	while (name[*j] && str[*i] != '$')
	{
		(*i)++;
		(*j)++;
	}
}
char *remplace_expand(char *str, char *name, char *value)
{
	int		i;
	int		j;
	int		k;
	int		n;
	char 	*new;

	remplace_expand_short(str, name, &k, &i, &j);
	n = i;
	new = malloc(sizeof(char) * (k + ft_strlen(value) + ft_strlen(str + i)) + 10);
	j = 0;
	i = 0;
	while (str[i] != '$')
		new[j++] = str[i++];
	k = 0;
	while(value[k])
		new[j++] = value[k++];
	while(str[n])
		new[j++] = str[n++];
	return (new);
}

int	find_expand(char *str, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '$')
		i++;
	i++;
	while (str[i] && str[i] != '$')
	{
		if (name[j] != str[i])
		{
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}
char    *expander(t_tokens tokens, t_env *env)
{
    while (env)
	{
		if (find_expand(tokens.str, env->name))
			return (remplace_expand(tokens.str, env->name,env->value));
		env = env->next;
	}
	return (no_expand(tokens.str));
}

void    ft_expander(t_tokens *tokens, t_env *env)
{
    int i;

    i = -1;
    while (tokens[++i].str)
    {
        if (tokens[i].str && tokens[i].dquote)
        {
            while (ft_strchr(tokens[i].str, '$'))
                tokens[i].str = expander(tokens[i], env);
		}
    }
}