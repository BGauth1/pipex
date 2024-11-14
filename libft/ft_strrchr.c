/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:17:06 by gbertet           #+#    #+#             */
/*   Updated: 2022/09/29 16:00:35 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buff;
	char	*result;

	buff = (char *)s;
	result = NULL;
	while (*buff != 0)
	{
		if (*buff == (char)c)
			result = buff;
		buff++;
	}
	if (*buff == (char)c)
		return (buff);
	return (result);
}
