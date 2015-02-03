/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:49:43 by jibanez           #+#    #+#             */
/*   Updated: 2014/05/14 17:43:52 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*new;
	int		i;

	if (s && f)
	{
		new = ft_strnew(ft_strlen(s));
		if (!new)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			new[i] = f((char)s[i]);
			i++;
		}
		return (new);
	}
	return (NULL);
}
