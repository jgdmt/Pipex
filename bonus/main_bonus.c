/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:38:43 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/11 15:21:01 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->count)
	{
		ft_free_strs(data->args[i], 0);
		free(data->cmds[i]);
	}
	free(data->cmds);
	free(data->args);
}

static void	ft_last(t_data *data, int i, char **envp, int *end)
{
	int		status;

	if (!data->pid)
	{
		dup2(data->f2, STDOUT_FILENO);
		close(end[1]);
		if (data->f2 == -1 || execve(data->cmds[i], data->args[i], envp) == -1)
		{
			ft_free_data(data);
			exit (1);
		}
	}
	else
	{
		close(end[0]);
		close(end[1]);
		waitpid(data->pid, &status, 0);
		data->status = WEXITSTATUS(status);
		return ;
	}
}

static void	ft_pipex(t_data *data, int i, char **envp, int *end)
{
	if (!data->pid)
	{
		dup2(end[1], STDOUT_FILENO);
		close(end[0]);
		if (execve(data->cmds[i], data->args[i], envp) == -1)
		{
			ft_free_data(data);
			exit (1);
		}
	}
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		waitpid(data->pid, NULL, 0);
	}
}

static void	ft_init_pipex(t_data *data, int i, char **envp)
{
	int		end[2];

	if (pipe(end) == -1)
	{
		perror("Pipe");
		exit (-1);
	}
	data->pid = fork();
	if (data->pid < 0)
		return ;
	if (i < data->count - 1)
		ft_pipex(data, i, envp, end);
	else
		ft_last(data, i, envp, end);
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;
	int		i;

	if (argc < 5)
		return (1);
	data = ft_init_data(argc, argv);
	ft_parse(&data, argv, envp);
	if (data.f1 != -1 || data.cmds[0])
		dup2(data.f1, 0);
	i = -1;
	if (data.f1 == -1)
		i = 0;
	while (++i < data.count)
		ft_init_pipex(&data, i, envp);
	ft_free_data(&data);
	return (data.status);
}
