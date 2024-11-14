/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:35:48 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/25 15:54:35 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putargs(va_list args, const char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'd' || s[i] == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (s[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (s[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (s[i] == 'x')
		len += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (s[i] == 'X')
		len += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (s[i] == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (s[i] == 'p')
		len += ft_putptr_base(va_arg(args, void *), "0123456789abcdef");
	else if (s[i] == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_putargs(args, s, i);
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
