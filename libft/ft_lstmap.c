/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:28:33 by gbertet           #+#    #+#             */
/*   Updated: 2022/10/12 18:02:24 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buff;
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	buff = lst;
	while (buff != NULL)
	{
		new_node = ft_lstnew((*f)((void *)buff->content));
		if (!new_node)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_node);
		buff = buff->next;
	}
	return (new_list);
}
