/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:28:23 by gbertet           #+#    #+#             */
/*   Updated: 2023/07/07 16:36:39 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_path(char **ev)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", ev[i], 5) && ev[i] != NULL)
		i++;
	return (ft_split(ev[i] + 5, ':'));
}

char	***get_cmds(int ac, char **av)
{
	char	***res;
	int		i;

	res = malloc((ac - 2) * sizeof(char **));
	if (!res)
		return (NULL);
	res[ac - 3] = NULL;
	i = 2;
	while (i < ac - 1)
	{
		res[i - 2] = ft_split_pipex(av[i], ' ');
		i++;
	}
	return (res);
}

void	get_pipes(t_pipex *pipex)
{
	if (pipe(pipex->pipes1) < 0)
		exit_str("Pipe error.\n", 2, pipex);
	if (pipe(pipex->pipes2) < 0)
		exit_str("Pipe error.\n", 2, pipex);
}

t_pipex	get_pipex(int ac, char **av, char **ev)
{
	t_pipex	pipex;

	if (ac < 5)
		exit_str("Incorrect number of arguments.\n", 2, NULL);
	if (empty_args(ac, av))
		exit_str("Some arguments are empty.\n", 2, NULL);
	pipex.cmd = NULL;
	pipex.paths = get_path(ev);
	if (!pipex.paths)
		exit_str("Allocation error.\n", 2, &pipex);
	pipex.cmds = get_cmds(ac, av);
	if (!pipex.cmds)
		exit_str("Allocation error.\n", 2, &pipex);
	pipex.fd_in = open(av[1], O_RDONLY);
	if (pipex.fd_in < 0)
		perror(av[1]);
	pipex.fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.fd_out < 0)
		perror(av[ac - 1]);
	return (pipex);
}
