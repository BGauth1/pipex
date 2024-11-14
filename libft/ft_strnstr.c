/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:39:32 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/13 18:06:28 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	i = 0;
	j = 0;
	if (len < 1 && !big)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	len_little = ft_strlen(little);
	while (big[j] != '\0')
	{
		i = 0;
		while ((big[i + j] == little[i]) && (j + len_little <= len))
		{
			if (little[i + 1] == '\0')
				return ((char *)&big[j]);
			i++;
		}
		j++;
	}
	return (NULL);
}
