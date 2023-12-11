/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:43:10 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/11 15:15:15 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_strs(char **board, int i)
{
	while (board && board[i])
		free(board[i++]);
	free(board);
}

static char	*ft_find_line(char **envp)
{
	unsigned int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	return (envp[i] + 5);
}

char	*ft_get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;

	paths = ft_split(ft_find_line(envp), ':');
	i = 0;
	while (paths && paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK | X_OK) != -1)
			return (ft_free_strs(paths, i + 1), path);
		free(path);
		i++;
	}
	return (free(paths), NULL);
}

t_data	ft_init_data(int argc, char **argv)
{
	t_data	data;
	int		f1;
	int		f2;

	f1 = open(argv[1], O_RDONLY);
	if (f1 == -1)
		perror("zsh");
	if (ft_strncmp("/dev/urandom", argv[1], 13) == 0)
		close(f1);
	if (!ft_strncmp("/dev/urandom", argv[1], 13))
		f1 = -1;
	f2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 00777);
	data.f1 = f1;
	data.f2 = f2;
	data.cmds = 0;
	data.args = 0;
	data.status = 0;
	data.count = argc - 3;
	return (data);
}
