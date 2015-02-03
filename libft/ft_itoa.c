/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:26:28 by jibanez           #+#    #+#             */
/*   Updated: 2014/05/14 17:40:16 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	while ((n / 10) != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	int		nb;

	nb = n;
	if (!(str = ft_strnew(ft_intlen(nb) + 1)))
		return (NULL);
	i = ft_intlen(nb) - 1;
	while (i > 0)
	{
		if (n < 0)
			str[i] = (char)(-(nb % 10) + '0');
		else
			str[i] = (char)((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	if (n < 0)
		str[i] = '-';
	else
		str[i] = (char)((nb % 10) + '0');
	return (str);
}
