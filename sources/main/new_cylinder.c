/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 10:39:30 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/28 14:39:10 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"

t_object		new_cylinder(t_vertex pos, float radius, t_vector rot)
{
	t_object	object;
	t_matrix	s;
	t_matrix	r;
	t_matrix	t;

	s = get_scale_matrix(radius, radius, radius);
	r = get_rot_matrix(rot.x, rot.y, rot.z);
	t = get_trans_matrix(pos.x, pos.y, pos.z);
	object.o2w = matrix_product(t, matrix_product(r, s));
	s = get_scale_matrix(1 / radius, 1 / radius, 1 / radius);
	object.no2w = matrix_product(t, matrix_product(r, s));
	t = get_trans_matrix(-pos.x, -pos.y, -pos.z);
	r = get_rot_matrix(-rot.x, -rot.y, -rot.z);
	s = get_scale_matrix(1 / radius, 1 / radius, 1 / radius);
	object.w2o = matrix_product(s, matrix_product(r, t));
	object.intersect = intersect_cylinder;
	object.get_normal = cylinder_normal;
	return (object);
}

t_object		get_cylinder(char **object, int id)
{
	t_object	cylinder;

	cylinder = new_cylinder(
		new_vector(ft_atoi(object[1]), ft_atoi(object[2]), ft_atoi(object[3])),
		ft_atoi(object[4]),
		new_vector(ft_atoi(object[5]), ft_atoi(object[6]), ft_atoi(object[7])));
	cylinder.color = new_color(
		ft_atoi(object[8]), ft_atoi(object[9]), ft_atoi(object[10]));
	cylinder.diffuse_color = new_vector(1, 1, 1);
	cylinder.id = id;
	return (cylinder);
}
