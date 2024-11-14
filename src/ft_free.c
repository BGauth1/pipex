/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:10:50 by gbertet           #+#    #+#             */
/*   Updated: 2023/07/07 17:01:51 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_close_all(int *pipes1, int *pipes2, int fd_in, int fd_out)
{
	close(pipes1[0]);
	close(pipes1[1]);
	close(pipes2[0]);
	close(pipes2[1]);
	if (fd_in > 0)
		close(fd_in);
	if (fd_out > 0)
		close(fd_out);
}

void	ft_free_str_size(char **s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_ultimate_free_str(char ***s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_free_str(s[i]);
		i++;
	}
	free(s);
}

void	exit_str(const char *str, int fd, t_pipex *pipex)
{
	if (str)
		write(fd, str, ft_strlen(str));
	if (pipex)
	{
		if (pipex->fd_in > 0)
			close(pipex->fd_in);
		if (pipex->fd_out > 0)
			close(pipex->fd_out);
		if (pipex->paths)
			ft_free_str(pipex->paths);
		if (pipex->cmds)
			ft_ultimate_free_str(pipex->cmds);
	}
	exit(fd - 1);
}
