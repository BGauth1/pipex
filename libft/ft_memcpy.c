/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:49:58 by gbertet           #+#    #+#             */
/*   Updated: 2022/09/30 15:46:09 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*buff_dest;
	char	*buff_src;

	i = 0;
	if (!src && !dest)
		return (dest);
	buff_dest = (char *)dest;
	buff_src = (char *)src;
	while (i < n)
	{
		*buff_dest = *buff_src;
		buff_dest++;
		buff_src++;
		i++;
	}
	return (dest);
}
