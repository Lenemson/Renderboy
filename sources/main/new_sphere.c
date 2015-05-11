/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 14:04:29 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/11 16:37:13 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_object		new_sphere(t_vertex pos, float radius, t_color color)
{
	t_object	object;
	t_matrix	t;
	t_matrix	s;

	t = get_trans_matrix(pos.x, pos.y, pos.z);
	s = get_scale_matrix(radius, radius, radius);
	object.o2w = matrix_product(t, s);
	t = get_trans_matrix(-pos.x, -pos.y, -pos.z);
	s = get_scale_matrix(1 / radius, 1 / radius, 1 / radius);
	object.w2o = matrix_product(s, t);
	object.color = color;
	object.intersect = intersect_sphere;
	return (object);
}
