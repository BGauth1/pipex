/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:55:23 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/19 16:25:31 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		len += ft_putchar('-');
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		n %= 10;
	}
	if (n < 10)
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putunbr(n / 10);
		n %= 10;
	}
	if (n < 10)
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
		i += ft_putchar(s[i]);
	return (i);
}
