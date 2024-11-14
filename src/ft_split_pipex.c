/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:35:53 by gbertet           #+#    #+#             */
/*   Updated: 2023/07/07 17:09:19 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_betweenchar(char *s, int pos, char cquote)
{
	int		i;
	int		quote;
	char	c;

	i = -1;
	quote = 0;
	c = '\0';
	if ((int)ft_strlen(s) <= pos)
		return (0);
	while (s[++i])
	{
		if (i == pos)
			return (quote && s[i] != c && c == cquote);
		else if (!quote && (s[i] == '\'' || s[i] == '\"'))
		{
			quote = 1;
			c = s[i];
		}
		else if (quote && s[i] == c)
			quote = 0;
	}
	return (0);
}

/*	Return 1 si le char s[pos] est entre des
	doubles/simples quotes, sinon return 0.	*/
int	ft_betweenquotes(char *s, int pos)
{
	if (pos < 0)
		return (0);
	return (ft_betweenchar(s, pos, '\'') || ft_betweenchar(s, pos, '\"'));
}

static int	ft_size_tab(const char *s, char c)
{
	int	i;
	int	size_tab;

	i = 0;
	size_tab = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c && !ft_betweenquotes((char *)s, i))
			i++;
		if (s[i] && (s[i] != c || ft_betweenquotes((char *)s, i)))
			size_tab++;
		while (s[i] && (s[i] != c || ft_betweenquotes((char *)s, i)))
			i++;
	}
	return (size_tab);
}

static int	ft_getnext(const char *s, char c, int *j)
{
	int	nb;

	nb = 0;
	while (s[*j] && s[*j] == c && !ft_betweenquotes((char *)s, *j))
		(*j)++;
	while (s[*j] && (s[*j] != c || ft_betweenquotes((char *)s, *j)))
	{
		(*j)++;
		nb++;
	}
	return (nb);
}

char	**ft_split_pipex(char const *s, char c)
{
	char	**tab;
	int		nb_tab;
	int		nb_char;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nb_tab = ft_size_tab(s, c);
	tab = malloc(sizeof(char *) * (nb_tab + 1));
	if (!tab)
		return (NULL);
	tab[nb_tab] = NULL;
	i = 0;
	j = 0;
	while (i < nb_tab)
	{
		nb_char = ft_getnext(s, c, &j);
		tab[i] = ft_substr(s, j - nb_char, nb_char);
		tab[i] = ft_remove_quotes(tab[i]);
		i++;
	}
	return (tab);
}
