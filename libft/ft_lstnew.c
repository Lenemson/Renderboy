/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:50:20 by jibanez           #+#    #+#             */
/*   Updated: 2014/05/14 17:40:28 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*lstnew;

	if (!(lstnew = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(lstnew->content = (void *)malloc(content_size)))
		{
			free(lstnew);
			return (NULL);
		}
		lstnew->content = ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
	}
	else
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	lstnew->next = NULL;
	return (lstnew);
}
