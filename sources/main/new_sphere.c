/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 14:04:29 by jibanez           #+#    #+#             */
/*   Updated: 2015/04/02 12:41:10 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include <stdio.h>//////

t_object		new_sphere(t_vertex pos, float radius, t_color color)
{
	t_object	sphere;
	t_matrix	t;
	t_matrix	s;
	t_matrix	r;

	t = get_trans_matrix(pos.x, pos.y, pos.z);
	s = get_scale_matrix(radius, radius, radius);
	r = get_rot_matrix(22, 33, 44);
	sphere.shape.sphere.w2o = matrix_product(s, t);
	sphere.color = color;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%f      ", sphere.shape.sphere.w2o.m[i][j]);
		printf("\n");
	}
	return (sphere);
}
