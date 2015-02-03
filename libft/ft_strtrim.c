/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:23:33 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/01 17:18:26 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	size_t	slen;
	size_t	start;
	size_t	i;

	if (s)
	{
		start = 0;
		slen = 0;
		while (ft_isspace(s[start]))
			start++;
		i = start;
		while (s[i] != '\0')
		{
			if (ft_isprint(s[i]) && !ft_isspace(s[i]))
				slen = (i - start) + 1;
			i++;
		}
		if ((new = ft_strsub(s, start, slen)))
			return (new);
		return (NULL);
	}
	else
		return (NULL);
}
