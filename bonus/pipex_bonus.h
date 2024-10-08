/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:35:25 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/11 15:15:48 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		f1;
	int		f2;
	char	**cmds;
	char	***args;
	int		count;
	int		here_doc;
	int		status;
	int		pid;
}	t_data;

t_data	ft_init_data(int argc, char **argv);
void	ft_parse(t_data *data, char **argv, char **envp);
void	ft_free_strs(char **board, int i);
char	*ft_get_path(char *cmd, char **envp);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);

#endif