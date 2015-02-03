/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:06:17 by jibanez           #+#    #+#             */
/*   Updated: 2013/11/28 12:43:02 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*run;

	if (alst && del)
	{
		while (*alst)
		{
			run = *alst;
			*alst = run->next;
			del(run->content, run->content_size);
		}
		free(*alst);
		*alst = NULL;
	}
}
