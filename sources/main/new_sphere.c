/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 14:04:29 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/23 18:28:41 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_object		new_sphere(t_vertex pos, float radius)
{
	t_object	object;
	t_matrix	s;
	t_matrix	t;

	s = get_scale_matrix(radius, radius, radius);
	t = get_trans_matrix(pos.x, pos.y, pos.z);
	object.o2w = matrix_product(t, s);
	s = get_scale_matrix(1 / radius, 1 / radius, 1 / radius);
	object.no2w = matrix_product(t, s);
	t = get_trans_matrix(-pos.x, -pos.y, -pos.z);
	s = get_scale_matrix(1 / radius, 1 / radius, 1 / radius);
	object.w2o = matrix_product(s, t);
	object.intersect = intersect_sphere;
	object.get_normal = sphere_normal;
	return (object);
}
