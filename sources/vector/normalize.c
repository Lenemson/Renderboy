/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:13:08 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/17 15:40:12 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	normalize(t_vector v)
{
	t_vector	normalized;

	normalized = div_vector(v, magnitude(v));
	return (normalized);
}
