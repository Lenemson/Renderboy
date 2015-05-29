/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:27:41 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/29 13:36:25 by jibanez          ###   ########.fr       */
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

	dst.x = src.x * m.m[0][0] + src.y * m.m[0][1] + src.z * m.m[0][2]
		+ m.m[0][3];
	dst.y = src.x * m.m[1][0] + src.y * m.m[1][1] + src.z * m.m[1][2]
		+ m.m[1][3];
	dst.z = src.x * m.m[2][0] + src.y * m.m[2][1] + src.z * m.m[2][2]
		+ m.m[2][3];
	w = src.x * m.m[3][0] + src.y * m.m[3][1] + src.z * m.m[3][2]
		+ m.m[3][3];
	if (w != 1 && w != 0)
	{
		dst.x /= w;
		dst.y /= w;
		dst.z /= w;
	}
	return (dst);
}
