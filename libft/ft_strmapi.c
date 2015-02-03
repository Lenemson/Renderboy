/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:10:38 by jibanez           #+#    #+#             */
/*   Updated: 2014/05/14 17:44:00 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (s && f)
	{
		new = ft_strnew(ft_strlen(s));
		if (!new)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			new[i] = f(i, (char)s[i]);
			i++;
		}
		return (new);
	}
	else
		return (NULL);
}
