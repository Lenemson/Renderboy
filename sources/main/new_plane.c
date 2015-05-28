/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 16:50:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/28 13:22:44 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"

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

t_object		get_plane(char **object, int id)
{
	t_object	plane;

	plane = new_plane(
		new_vector(ft_atoi(object[1]), ft_atoi(object[2]), ft_atoi(object[3])),
		ft_atoi(object[4]), ft_atoi(object[5]), ft_atoi(object[6]));
	plane.color = new_color(
		ft_atoi(object[7]), ft_atoi(object[8]), ft_atoi(object[9]));
	plane.diffuse_color = new_vector(1, 1, 1);
	plane.id = id;
	return (plane);
}
