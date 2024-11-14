/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:24:35 by gbertet           #+#    #+#             */
/*   Updated: 2023/07/08 17:32:07 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*join_full_cmd(char *cmd, char **paths)
{
	char	*res;
	char	*path;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		path = ft_strjoin(paths[i], "/");
		res = ft_strjoin(path, cmd);
		free(path);
		if (!res)
			return (res);
		if (!access(res, 0))
			return (res);
		free(res);
		res = NULL;
		i++;
	}
	if (!access(cmd, X_OK))
		res = ft_strdup(cmd);
	return (res);
}

void	exec_command_odd(t_pipex pipex, int n_cmd, int ac, char **ev)
{	
	if (fork() == 0)
	{
		if (n_cmd == 0)
		{
			dup2(pipex.fd_in, 0);
			dup2(pipex.pipes1[1], 1);
		}
		else if (n_cmd == ac - 4)
		{
			dup2(pipex.pipes2[0], 0);
			dup2(pipex.fd_out, 1);
		}
		else
		{
			dup2(pipex.pipes2[0], 0);
			dup2(pipex.pipes1[1], 1);
		}
		ft_close_all(pipex.pipes1, pipex.pipes2, pipex.fd_in, pipex.fd_out);
		if (execve(pipex.cmd, pipex.cmds[n_cmd], ev) == -1)
			perror(pipex.cmds[n_cmd][0]);
		close(0);
		close(1);
		free(pipex.cmd);
		exit_str("", 2, &pipex);
	}
}

void	exec_command_even(t_pipex pipex, int n_cmd, int ac, char **ev)
{	
	if (fork() == 0)
	{
		if (n_cmd == ac - 4)
		{
			dup2(pipex.pipes1[0], 0);
			dup2(pipex.fd_out, 1);
		}
		else
		{
			dup2(pipex.pipes1[0], 0);
			dup2(pipex.pipes2[1], 1);
		}
		ft_close_all(pipex.pipes1, pipex.pipes2, pipex.fd_in, pipex.fd_out);
		if (execve(pipex.cmd, pipex.cmds[n_cmd], ev) == -1)
			perror(pipex.cmds[n_cmd][0]);
		close(0);
		close(1);
		free(pipex.cmd);
		exit_str("", 2, &pipex);
	}
}

void	exec_command(t_pipex pipex, int i, int ac, char **ev)
{
	pipex.cmd = join_full_cmd(pipex.cmds[i][0], pipex.paths);
	if (pipex.cmd)
	{
		if (i % 2 == 0)
		{
			exec_command_odd(pipex, i, ac, ev);
			close(pipex.pipes2[0]);
			close(pipex.pipes2[1]);
			pipe(pipex.pipes2);
		}
		else if (i % 2 == 1)
		{
			exec_command_even(pipex, i, ac, ev);
			close(pipex.pipes1[0]);
			close(pipex.pipes1[1]);
			pipe(pipex.pipes1);
		}
		free(pipex.cmd);
	}
	else
		perror(pipex.cmds[i][0]);
}
