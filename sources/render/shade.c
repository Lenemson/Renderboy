/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 13:24:45 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/28 14:07:13 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_vector		get_light(t_light light, t_vertex isec, t_vector normal)
{
	t_ray		rlight;
	float		angle;

	rlight.o = isec;
	rlight.dir = vector_diff(light.pos, rlight.o);
	angle = dot_product(normalize(rlight.dir), normalize(normal));
	if (angle > 0)
		return (mult_vector(light.color, angle));
	else
		return (new_color(0, 0, 0));
}

t_vector		shade(t_scene *scene, t_object hit, t_ray ray, float t)
{
	t_vector	lcolor;
	t_vector	color;
	t_vertex	isec;
	t_vector	normal;
	int			i;

	color = new_vector(0, 0, 0);
	isec = vector_sum(mult_vector(ray.dir, t), ray.o);
	normal = hit.get_normal(isec);
	isec = mult_matrix_vertex(isec, hit.o2w);
	if (dot_product(normalize(ray.dir), normalize(normal)) > 0)
			normal = mult_vector(normal, -1);
	normal = mult_matrix_vector(normal, hit.no2w);
	i = 0;
	while (i < scene->n_lights)
	{
		lcolor = get_light(scene->light[i], isec, normal);
		color = color_lerp(color, hit.color, lcolor);
		i++;
	}
	return (color);
}

