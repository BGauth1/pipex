/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:28:29 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/13 17:17:33 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	isalpha;
	int	isdigit;

	isalpha = ft_isalpha(c);
	isdigit = ft_isdigit(c);
	if (isalpha || isdigit)
		return (1);
	return (0);
}
