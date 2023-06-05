/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:41:09 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/05 18:09:12 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//------------------INCLUDES------------------//

# include <stdio.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/signal.h>

# define BUFFER_SIZE 1000
//-------------------STRUCT-------------------//

typedef struct s_tokens
{
	char				*str;
	int					spcecho;
}	t_tokens;

//-------------------LEXER-------------------//
	//is
int				ft_isspace(int c);
int				ft_issep(int c);
int				ft_isquote(int c);
int				ft_isfle(int c);
int				ft_isspcable(int c);
	//malloc split
size_t			cpt_quote(char *s);
size_t			cpt_word(char *str, int a);
size_t			ft_cptword(char *args);
	//sep
char			*ft_remove_spcqu(char *arg);
char			*ft_add_spcqu(char *arg);
char			*ft_remove_spc(char *arg);
char			*ft_add_spc(char *arg);
char			*ft_remove_quotes(char *str);
char			*ft_add_spcqu(char *arg);
char			*ft_rmspc(char *arg);
	//split
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
t_tokens		*ft_lexer(char *args);
void			ft_lasttoken(char **token);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				is_arrow(char *token);
char			*concat_tokens(char *token1, char *token2);
void			compact_array(char **token, int j, int i);
void			concat_arrow(char **token);
char			**tokentostr(t_tokens *token);

//-------------------UTILS-------------------//
int				ft_onlyspace(char *str);
int				ft_cinstr(char *str, char c);
size_t			ft_strlen(const char *str);
void			ft_putstr_fd(char *str, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);

//-------------------ERROR-------------------//
int				error_quote(char *str);
int				err_unclosed_quote(char *str);

#endif
