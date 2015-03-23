/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:17:43 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/23 17:31:57 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

/*
** 00 01 02 03
** 10 11 12 13
** 20 21 22 23
** 30 31 32 33
*/
t_vector	mult_matrix_vector(t_vector const src, t_matrix const m)
{
	t_vector	dst;

	dst.x = src.x * m.c[0][0] + src.y * m.c[1][0] + src.z * m.c[2][0];
	dst.y = src.x * m.c[0][1] + src.y * m.c[1][1] + src.z * m.c[2][1];
	dst.z = src.x * m.c[0][2] + src.y * m.c[1][2] + src.z * m.c[2][2];

	return (dst);
}

