/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:35:39 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/18 13:01:08 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Also known as scalar product due to returning a scalar, the dot product
** help know if two vector share the same direction
** This function need normalized vectors
** 1 = same direction, -1 = oposite direction
*/

float		dot_product(const t_vector a, const t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
