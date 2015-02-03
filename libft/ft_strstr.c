/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:28:20 by jibanez           #+#    #+#             */
/*   Updated: 2014/05/14 17:45:17 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find the first occurence of find in s
*/

char	*ft_strstr(const char *s, const char *find)
{
	char	sc;
	size_t	len;

	len = ft_strlen(find);
	while (ft_strncmp(s, find, len) != 0)
	{
		sc = *s++;
		if (sc == '\0')
			return (NULL);
	}
	return ((char *)s);
}
