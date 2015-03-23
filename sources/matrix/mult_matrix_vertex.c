/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:27:41 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/23 17:32:23 by jibanez          ###   ########.fr       */
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
t_vertex		mult_matrix_vertex(t_vertex const src, t_matrix const m)
{
	t_vertex	dst;
	float		w;

	dst.x = src.x * m.c[0][0] + src.y * m.c[1][0] + src.z * m.c[2][0] + m.c[3][0];
	dst.y = src.x * m.c[0][1] + src.y * m.c[1][1] + src.z * m.c[2][1] + m.c[3][1];
	dst.z = src.x * m.c[0][2] + src.y * m.c[1][2] + src.z * m.c[2][2] + m.c[3][2];

	w = src.x * m.c[0][3] + src.y * m.c[1][3] + src.z * m.c[2][3] + m.c[3][3];
	if (w != 1 && w != 0)
	{
		dst.x /= w;
		dst.y /= w;
		dst.z /= w;
	}
	return (dst);
}

