/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 11:08:04 by jibanez           #+#    #+#             */
/*   Updated: 2014/05/14 17:41:20 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Return the size of string str till enounter char c of '\0'
*/

size_t	ft_strclen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != (const char)c && str[i] != '\0')
		i++;
	return (i);
}
