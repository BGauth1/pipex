/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:02:02 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/13 18:37:11 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlen;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (len > strlen)
		len = strlen;
	if (start > strlen)
		len = 0;
	else if (len + start > strlen)
		len = strlen - start;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}
