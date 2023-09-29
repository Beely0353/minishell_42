/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:46:54 by biaroun           #+#    #+#             */
/*   Updated: 2023/09/29 05:07:58 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *no_expand(char *str)
{
    int     i;
    int     j;
    char    *new;

    i = 0;
    while (str[i] != '$')
        i++;
    j = i++;
    while (str[i] != '$' && str[i])
        i++;
    new = malloc(sizeof(char*) * (ft_strlen(str) - (i - j) + 1));
    i = 0;
    j = 0;
    while (str[i] != '$')
        new[j++] = str[i++];
    i++;
    while (str[i] != '$' && str[i])
        i++;
    while (str[i])
        new[j++] = str[i++];
    new[j] = '\0';
    free(str);
    return (new);
}