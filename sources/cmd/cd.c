/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:42:25 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/15 16:35:04 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	modify_pwd(t_env *envlst, char *new_pwd)
{
	t_env *pwd;
	t_env *old_pwd;
	int		i;
	int		j;

	pwd = envlst;
	old_pwd = envlst;
	j = ft_strlen(new_pwd) - 1;
	while (ft_strcmp(pwd->name, "PWD") != 0)
		pwd = pwd->next;
	while (ft_strcmp(old_pwd->name, "OLDPWD") != 0)
		old_pwd = old_pwd->next;
	free(old_pwd->value);
	old_pwd->value = ft_strdup(pwd->value);
	free(pwd->value);
	pwd->value = malloc(sizeof(char) * j);
	i = -1;
	while (++i != j)
		pwd->value[i] = new_pwd[i];
}*/

void	modify_pwd(t_env *envlst, char *new_pwd)
{
	t_env *pwd;
	t_env *old_pwd;
	int		j;

	pwd = envlst;
	old_pwd = envlst;
	j = ft_strlen(new_pwd) - 1;
	while (ft_strcmp(pwd->name, "PWD") != 0)
		pwd = pwd->next;
	while (ft_strcmp(old_pwd->name, "OLDPWD") != 0)
		old_pwd = old_pwd->next;
	free(old_pwd->value);
	old_pwd->value = ft_strdup(pwd->value);
	free(pwd->value);
	pwd->value = ft_strdup(getcwd(NULL, 0));
}

int	cd_no_dir(t_minishell *minishell)
{
	char	*HOME;

	HOME = get_env_value("HOME", minishell->envlst);
	if (HOME == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		minishell->re = 1;
		return (1);
	}
	if(chdir(HOME))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(HOME, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		minishell->re = 1;
		return (1);
	}
	modify_pwd(minishell->envlst, HOME);
	return (0);
}

void	cd_absolute(t_minishell *minishell, char *path)
{
	if (chdir(path))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		minishell->re = 1;
		return ;
	}
	modify_pwd(minishell->envlst, path);
	return ;
}

void	cd_relative(t_minishell *minishell, char *path)
{
	char	*PWD;
	char	*new_path;

	PWD = get_env_value("PWD", minishell->envlst);
	if (PWD == NULL)
	{
		ft_putstr_fd("minishell: cd: PWD not set\n", 2);
		minishell->re = 1;
		return ;
	}
	new_path = ft_strjoin(PWD, "/");
	new_path = ft_strjoin(new_path, path);
	printf("new_path: %s\n", new_path);
	if (chdir(new_path))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		minishell->re = 1;
	}
	modify_pwd(minishell->envlst, new_path);
	free(new_path);
	return ;
}

void	ft_cd(t_minishell *minishell, t_tokens *tokens)
{
	char	*old;

	minishell->re = 0;
	old = getcwd(NULL, 0);
	if (tokens[1].str == NULL)
	{
		if(cd_no_dir(minishell))
			return ;
	}
	else if (tokens[1].str[0] == '/')
		cd_absolute(minishell, tokens[1].str);
	else
		cd_relative(minishell, tokens[1].str);
	return ;
}
