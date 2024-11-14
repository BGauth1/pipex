/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:48:57 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/18 16:34:57 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_trim(char *res, const char *s, int *i, int *start_trim)
{
	res[*i] = s[*start_trim];
	*i = *i + 1;
	*start_trim = *start_trim + 1;
}

static void	ft_start_trim(const char *s, const char *set,
					int *start_trim, int end_trim)
{
	int	check_set;

	check_set = ft_check_set(s[*start_trim], set);
	while (check_set == 1 && *start_trim < end_trim - 1)
	{
		*start_trim = *start_trim + 1;
		check_set = ft_check_set(s[*start_trim], set);
	}
}

static void	ft_end_trim(const char *s, const char *set,
					int start_trim, int *end_trim)
{
	int	check_set;

	check_set = ft_check_set(s[*end_trim - 1], set);
	while (check_set == 1 && start_trim < *end_trim - 1)
	{
		*end_trim = *end_trim - 1;
		check_set = ft_check_set(s[*end_trim - 1], set);
	}
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		start_trim;
	int		end_trim;
	int		i;
	int		check_set;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start_trim = 0;
	end_trim = ft_strlen(s1);
	ft_start_trim(s1, set, &start_trim, end_trim);
	ft_end_trim(s1, set, start_trim, &end_trim);
	check_set = ft_check_set(s1[start_trim], set);
	if (start_trim == end_trim - 1 && check_set == 1)
		start_trim = end_trim;
	res = malloc((end_trim - start_trim + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (start_trim < end_trim)
		ft_trim(res, s1, &i, &start_trim);
	res[i] = '\0';
	return (res);
}
