/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:19:03 by jibanez           #+#    #+#             */
/*   Updated: 2013/12/06 19:41:58 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	slen1;
	size_t	slen2;

	if (s1 && s2)
	{
		slen1 = ft_strlen(s1);
		slen2 = ft_strlen(s2);
		if ((new = ft_strnew(slen1 + slen2 + 1)) == NULL)
			return (NULL);
		i = 0;
		while (i < slen1 + slen2)
		{
			if (i < slen1)
				new[i] = s1[i];
			else
				new[i] = *s2++;
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
