/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:13:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/23 16:09:29 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_object		new_cone(t_vertex pos, float radius, t_vector rot)
{
	t_object	object;
	t_matrix	s;
	t_matrix	r;
	t_matrix	t;

	s = get_scale_matrix(radius, 1, radius);
	r = get_rot_matrix(rot.x, rot.y, rot.z);
	t = get_trans_matrix(pos.x, pos.y, pos.z);
	object.o2w = matrix_product(t, matrix_product(r, s));
	s = get_scale_matrix(1 / radius, 1, 1 / radius);
	object.no2w = matrix_product(t, matrix_product(r, s));
	t = get_trans_matrix(-pos.x, -pos.y, -pos.z);
	r = get_rot_matrix(-rot.x, -rot.y, -rot.z);
	s = get_scale_matrix(1 / radius, 1, 1 / radius);
	object.w2o = matrix_product(s, matrix_product(r, t));
	object.intersect = intersect_cone;
	object.get_normal = cone_normal;
	return (object);
}
