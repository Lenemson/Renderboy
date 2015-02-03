/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:17:25 by jibanez           #+#    #+#             */
/*   Updated: 2014/01/16 20:16:36 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s)
	{
		if ((new = ft_strnew(len + 1)) == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			new[i] = (char)s[start];
			i++;
			start++;
		}
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
