/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:04:44 by gbertet           #+#    #+#             */
/*   Updated: 2023/07/08 17:35:38 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		pipes1[2];
	int		pipes2[2];
	char	***cmds;
	char	**paths;
	char	*cmd;
}				t_pipex;

//			MAIN.C			//
int		empty_args(int ac, char **av);

//          INIT.C          //
t_pipex	get_pipex(int ac, char **av, char **ev);

//			FREE.C			//
void	ft_free_str_size(char **s, int size);
void	exit_str(const char *str, int fd, t_pipex *pipex);
void	ft_close_all(int *pipes1, int *pipes2, int fd_in, int fd_out);

//			COMMANDS.C		//
void	exec_command(t_pipex pipex, int i, int ac, char **ev);
void	exec_command_odd(t_pipex pipex, int n_cmd, int ac, char **ev);
void	exec_command_even(t_pipex pipex, int n_cmd, int ac, char **ev);
char	*join_full_cmd(char *cmd, char **paths);

//		FT_SPLIT_PIPEX.C	//
char	**ft_split_pipex(char const *s, char c);

//			FT_UTILS.C		//
char	*ft_remove_quotes(char *s);

#endif