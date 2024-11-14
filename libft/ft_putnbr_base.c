/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:15:36 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/25 15:51:23 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned int nbr, const char *base)
{
	unsigned int	base_nb;
	int				len;

	base_nb = ft_strlen(base);
	len = 0;
	if (nbr > base_nb - 1)
	{
		len += ft_putnbr_base(nbr / base_nb, base);
		nbr %= base_nb;
	}
	if (nbr < base_nb)
		len += write(1, &base[nbr], 1);
	return (len);
}

static int	ft_writeptr_base(unsigned long int nbr, const char *base)
{
	unsigned long int	base_nb;
	int					len;

	base_nb = ft_strlen(base);
	len = 0;
	if (nbr > base_nb - 1)
	{
		len += ft_writeptr_base(nbr / base_nb, base);
		nbr %= base_nb;
	}
	if (nbr < base_nb)
		len += write(1, &base[nbr], 1);
	return (len);
}

int	ft_putptr_base(void *ptr, const char *base)
{
	unsigned long int	nbr;
	int					len;

	nbr = (unsigned long int)ptr;
	len = 0;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += write(1, "0x", 2);
	len += ft_writeptr_base(nbr, base);
	return (len);
}
