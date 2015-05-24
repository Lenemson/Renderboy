/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 16:50:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/23 16:10:04 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_object		new_plane(t_vertex pos, float ax, float ay, float az)
{
	t_object	object;
	t_matrix	r;
	t_matrix	t;

	r = get_rot_matrix(ax, ay, az);
	t = get_trans_matrix(pos.x, pos.y, pos.z);
	object.o2w = matrix_product(t, r);
	object.no2w = matrix_product(t, r);
	t = get_trans_matrix(-pos.x, -pos.y, -pos.z);
	r = get_rot_matrix(-ax, -ay, -az);
	object.w2o = matrix_product(r, t);
	object.intersect = intersect_plane;
	object.get_normal = plane_normal;
	return (object);
}
