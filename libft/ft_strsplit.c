/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:24:41 by jibanez           #+#    #+#             */
/*   Updated: 2014/05/14 17:45:03 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_splitnb(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			nb++;
		i++;
	}
	return (nb);
}

static char		**ft_split(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if ((split[j] = ft_strsub(s, i, ft_strclen(&s[i], c))) == NULL)
				return (NULL);
			i += ft_strclen(&s[i], c);
			j++;
		}
		else
			i++;
	}
	split[j] = '\0';
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;

	if (s)
	{
		new = (char **)malloc(sizeof(char *) * (ft_splitnb(s, c) + 1));
		if (!new)
			return (NULL);
		new = ft_split(s, c, new);
		return (new);
	}
	else
		return (NULL);
}
