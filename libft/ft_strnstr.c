/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:07:35 by jibanez           #+#    #+#             */
/*   Updated: 2014/05/14 17:44:12 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find the first occurence of find in s within n first character
*/

char	*ft_strnstr(const char *s, const char *find, size_t n)
{
	char	sc;
	size_t	len;

	len = ft_strlen(find);
	if (len > n)
		return (NULL);
	while (ft_strncmp(s, find, len) != 0)
	{
		sc = *s++;
		if (sc == '\0' || n-- < 1 || len > n)
			return (NULL);
	}
	return ((char *)s);
}
