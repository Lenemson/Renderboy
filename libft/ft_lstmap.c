/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:55:02 by jibanez           #+#    #+#             */
/*   Updated: 2013/11/29 12:46:09 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_del(void *d, size_t s)
{
	free(d);
	(void)s;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*begin;
	t_list	*new_lst;

	if (lst && f)
	{
		lst = f(lst);
		if (!(begin = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new_lst = begin;
		while (lst->next)
		{
			lst = f(lst->next);
			new_lst->next = ft_lstnew(lst->content, lst->content_size);
			new_lst = new_lst->next;
			if (!(new_lst))
			{
				ft_lstdel(&begin, ft_del);
				return (NULL);
			}
		}
		return (begin);
	}
	return (NULL);
}
