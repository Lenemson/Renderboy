/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:53:49 by jibanez           #+#    #+#             */
/*   Updated: 2013/12/17 10:54:39 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	unsigned const char	*ptr2;

	ptr1 = dest;
	ptr2 = src;
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			ptr1[n] = ptr2[n];
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
