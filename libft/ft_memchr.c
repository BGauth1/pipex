/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:00:42 by gbertet           #+#    #+#             */
/*   Updated: 2022/09/29 15:45:21 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	size_t			i;

	buff = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*buff == (unsigned char)c)
			return (buff);
		i++;
		buff++;
	}
	return (NULL);
}
