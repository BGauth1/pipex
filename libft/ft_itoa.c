/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:15:23 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/18 16:29:31 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_size(int n)
{
	int	int_size;
	int	minus;

	int_size = 1;
	minus = 0;
	if (n < 0)
		minus = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		int_size++;
	}
	int_size += minus;
	return (int_size);
}

static void	ft_stritoa(char *res, int int_size, int n)
{
	while (n != 0)
	{
		int_size--;
		res[int_size] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		int_size;

	int_size = ft_int_size(n);
	res = malloc((int_size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '0';
	res[int_size] = '\0';
	if (n == -2147483648)
	{
		ft_strlcpy(res, "-2147483648", 12);
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	ft_stritoa(res, int_size, n);
	return (res);
}
