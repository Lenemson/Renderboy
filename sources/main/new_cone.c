/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:13:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/28 14:47:26 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"

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

t_object		get_cone(char **object, int id)
{
	t_object	cone;

	cone = new_cone(
		new_vector(ft_atoi(object[1]), ft_atoi(object[2]), ft_atoi(object[3])),
		(float)(ft_atoi(object[4])) / 90,
		new_vector(ft_atoi(object[5]), ft_atoi(object[6]), ft_atoi(object[7])));
	cone.color = new_color(
		ft_atoi(object[8]), ft_atoi(object[9]), ft_atoi(object[10]));
	cone.diffuse_color = new_vector(1, 1, 1);
	cone.id = id;
	return (cone);
}
