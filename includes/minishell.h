/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:39 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 20:16:56 by baroun           ###   ########.fr       */
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
typedef struct s_env
{
	char	*name;
	char	*value;
}	t_env;

typedef struct s_minishell
{
	t_env	*env;
	int		env_size;
	char	**builtins;
	size_t	last_token_size;
	char	**envp;
	pid_t	cur_proc_pid;
}	t_minishell;

typedef enum e_token_type
{
	TOKEN_CMD,
	TOKEN_REDIR,
	TOKEN_SEP,
	TOKEN_END
}	t_token_type;

typedef enum e_redirection_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	REDIR_PIPE,
	REDIR_ERROR
}	t_redir_type;

typedef struct s_tokens
{
	char				*str;
	int					spcecho;
}	t_tokens;

typedef struct s_parser_token
{
	t_token_type		type;
	t_redir_type		redirection[5];
	char				**command;
	size_t				command_size;
	char				*input;
	size_t				input_size;
	char				*output;
	size_t				output_size;
	t_tokens			*tokens;
}	t_parser_token;

t_minishell	*g_minishell;
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

//-------------------PARSER-------------------//
t_parser_token	*ft_parse_tokens(char **tks, t_tokens *tk);
void			print_token(t_parser_token *token);
void			parse_redirect_token(char *token, t_parser_token *parsed_token);
void			parse_separator_token(char *token, t_parser_token *parsed_tok);
void			parse_command_token(char **tk, size_t i, t_parser_token *p_tk);
int				is_redirect(char *token);
t_redir_type	get_redir_type(char *token);
void			remove_empty_cmd(t_parser_token *parsed_tokens);
char			*ft_strchr(const char *s, int c);

//------------------COMMANDS------------------//
int				ft_cd(t_parser_token *token);
int				ft_echo(t_parser_token *token);
int				ft_env(t_parser_token *token);
int				ft_export(t_parser_token *token);
int				ft_pwd(t_parser_token *token);
int				ft_unset(t_parser_token *token);
int				ft_exit(t_parser_token *token);
int				ft_clear(t_parser_token *token);
int				ft_history(t_parser_token *token);

//-------------------EXEC-------------------//
void			redir_fds(int fd_in, int fd_out);
int				ft_executor(t_parser_token *tokens);
char			*ft_strcat(char *dest, char *src);
int				cmd_exists(t_parser_token *token);
char			*ft_itoa(int n);
void			ft_bzero(void *s, size_t n);
int				exec_builtin(t_parser_token *token);
int				is_builtin(char *str);
int				execute_command(t_parser_token *token,
					int fd_in, int fd_out, int fd[2]);
int				execute_builtin(t_parser_token *token,
					int fd_in, int fd_out);
char			*read_heredoc(char *delimiter);
int				execute_command(t_parser_token *token, int fd_in, \
int fd_out, int fd[2]);

//-------------------REDIRECTION-------------------//
int				handle_redirections_out(t_parser_token *tokens, int i, \
int *skip_next_cmd);
int				handle_redirections_in(t_parser_token *tokens, int i, \
int *skip_next_cmd);
//-------------------SIGNAL-------------------//
void			echo_control_seq(int c);
void			init_signal(void);

//-------------------ERROR-------------------//
int				error_quote(char *str);
int				err_unclosed_quote(char *str);
char			**listofcmd(void);
int				check_cmd(char *str);
int				ft_cmdcmp(char *s1, char **s2);
int				ft_strcmp(const char *s1, const char *s2);
void			err_not_found(char *cmd);
void			ft_split_free(char **split);
void			err_perm_denied(char *cmd);

//-------------------UTILS-------------------//
int				ft_onlyspace(char *str);
int				ft_cinstr(char *str, char c);
size_t			ft_strlen(const char *str);

//-------------------ENV-------------------//
void			*ft_realloc(void *ptr, size_t size);
void			ft_addenv(char *name, char *value);
void			ft_delenv(char *name);
void			ft_modenv(char *name, char *new_value);
char			*ft_getenv(char *name);
void			ft_initenv(char **env);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
void			print_env(void);

//-------------------EXPANDER-------------------//
void			ft_expander(t_parser_token *token);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strcpy(char *dest, const char *src);

//-------------------VALIDATOR-------------------//
int				ft_validator(t_parser_token *tokens);
char			*redir_type_to_str(t_parser_token *token);
int				ft_isalpha(char c);
int				ft_isdigit(int c);
void			ft_freeall(char **token, char *str);
void			ft_perror_cmd(char *cmd);
#endif
