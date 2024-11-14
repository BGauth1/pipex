/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:32:08 by gbertet           #+#    #+#             */
/*   Updated: 2023/07/07 16:50:50 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	empty_args(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < ac)
	{
		j = 0;
		c = av[i][j];
		while (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r')
			c = av[i][++j];
		if (av[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **ev)
{
	t_pipex	pipex;
	int		end;
	int		i;

	i = 0;
	pipex = get_pipex(ac, av, ev);
	if (pipex.fd_out < 0)
		end = ac - 4;
	else
		end = ac - 3;
	if (pipex.fd_in < 0)
		i = 1;
	pipe(pipex.pipes1);
	pipe(pipex.pipes2);
	while (i < end)
	{
		exec_command(pipex, i, ac, ev);
		i++;
	}
	ft_close_all(pipex.pipes1, pipex.pipes2, pipex.fd_in, pipex.fd_out);
	waitpid(-1, NULL, 0);
	exit_str("", 1, &pipex);
}
