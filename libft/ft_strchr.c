/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:17:06 by gbertet           #+#    #+#             */
/*   Updated: 2022/09/29 15:57:39 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buff;

	buff = (char *)s;
	while (*buff != 0)
	{
		if (*buff == (char)c)
			return (buff);
		buff++;
	}
	if (*buff == (char)c)
		return (buff);
	return (NULL);
}
