#include "minishell.h"

void	ft_doc(char	*delim, int fd, t_env *envlst, t_tokens	*line, t_minishell *mini)
{
	while (1)
	{
		
		line->str = readline("> ");
		if (!line->str)
			break ;
		line->dquote = 1;
		ft_expander(line, envlst, mini);
		if (ft_strcmp(line->str, delim) == 0)
		{
			free(line->str);
			break ;
		}
		write(fd, line->str, ft_strlen(line->str));
		write(fd, "\n", 1);
		free(line->str);
	}
}

char	*ft_heredoc(t_minishell *mini, t_tokens *delim)
{
	char		*here;
	int			fd;
	char		*rand;
	t_tokens	*line;

	rand = ft_itoa(ft_random());
	here = ft_strjoin("/tmp/heredoc", rand);
	free(rand);
	fd = open(here, O_WRONLY | O_CREAT | O_TRUNC, 0644);//voir si a supprimer
	if (fd == -1)
	{
		free(here);
		perror("open");
		mini->re = 1;
		return (NULL);
	}
	line = malloc(sizeof(t_tokens) * 2);
	line[1].str = NULL;
	ft_doc(delim->str, fd, mini->envlst, line, mini);
	close(fd);
	free(line);
	return (here);
}
