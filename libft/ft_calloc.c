/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:07:18 by gbertet           #+#    #+#             */
/*   Updated: 2022/09/30 16:30:25 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb >= 65535 && size >= 65535)
		ptr = NULL;
	else
	{
		if (nmemb == 0 || size == 0)
		{
			nmemb++;
			size++;
		}
		ptr = malloc(nmemb * size);
	}
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
