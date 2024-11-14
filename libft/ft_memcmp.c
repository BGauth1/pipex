/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:00:42 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/13 17:33:36 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buff_s1;
	unsigned char	*buff_s2;
	size_t			i;
	int				result;

	buff_s1 = (unsigned char *)s1;
	buff_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (buff_s1[i] != buff_s2[i])
		{
			result = buff_s1[i] - buff_s2[i];
			return (result);
		}
		i++;
	}
	return (0);
}
