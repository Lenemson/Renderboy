/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 14:04:29 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/28 14:34:27 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"


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

t_object		get_sphere(char **object, int id)
{
	t_object	sphere;

	sphere = new_sphere(
		new_vector(ft_atoi(object[1]), ft_atoi(object[2]), ft_atoi(object[3])),
		ft_atoi(object[4]));
	sphere.color = new_color(
		ft_atoi(object[5]), ft_atoi(object[6]), ft_atoi(object[7]));
	sphere.diffuse_color = new_vector(1, 1, 1);
	sphere.id = id;
	return (sphere);
}
