/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:31:26 by gbertet           #+#    #+#             */
/*   Updated: 2023/01/04 14:23:50 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_set_null(void *ptr)
{
	free(ptr);
	return (NULL);
}

char	*shorten_stash(char *stash, int end_line_index)
{
	int	i;

	i = 0;
	while (stash[end_line_index + i] != '\0')
	{
		stash[i] = stash[end_line_index + 1 + i];
		i++;
	}
	while (stash[i] != '\0')
	{
		stash[i] = '\0';
		i++;
	}
	if (stash[0] == '\0' && end_line_index < BUFFER_SIZE)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

int	end_line_index(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_stash(char *stash, int fd)
{
	int	i;

	i = 0;
	if (!stash)
	{
		stash = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!stash[0])
	{
		i = read(fd, stash, BUFFER_SIZE);
		if (i < 0)
		{
			free(stash);
			return (NULL);
		}
		stash[i] = '\0';
	}
	if (!stash[0])
		stash = ft_set_null(stash);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[2048];
	char		*str;
	int			eli;

	stash[fd] = get_stash(stash[fd], fd);
	if (!stash[fd] || BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	eli = end_line_index(stash[fd]);
	str = malloc((eli + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (stash[fd])
	{
		ft_strlcat(str, stash[fd], eli + 2);
		stash[fd] = shorten_stash(stash[fd], end_line_index(stash[fd]));
		if (str[eli] == '\n')
			return (str);
		stash[fd] = get_stash(stash[fd], fd);
		if (!stash[fd])
			return (str);
		str = ft_realloc(str, eli + 2, eli + 2 + end_line_index(stash[fd]));
		eli += end_line_index(stash[fd]);
	}
	return (str);
}
