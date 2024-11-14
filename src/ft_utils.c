/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:43:31 by gbertet           #+#    #+#             */
/*   Updated: 2023/07/07 17:16:17 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*remove_char(char *s, int pos)
{
	while (s[pos])
	{
		s[pos] = s[pos + 1];
			pos++;
	}
	s[ft_strlen(s)] = '\0';
	return (s);
}

char	*ft_remove_quotes(char *s)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	if (!s)
		return (s);
	while (s[i])
	{
		if (!c && (s[i] == '\'' || s[i] == '\"'))
		{
			c = s[i];
			s = remove_char(s, i);
		}
		else if (c == s[i])
		{
			c = '\0';
			s = remove_char(s, i);
		}
		else
			i++;
	}
	return (s);
}
