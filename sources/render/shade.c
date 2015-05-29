/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 13:24:45 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/29 11:57:25 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_vector	get_light(t_light light, t_vertex isec, t_vector normal)
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

static int		get_shadow(t_scene *scene, t_light light, t_vertex isec, int id)
{
	t_ray		lray;
	int			i;

	i = 0;
	while (i < scene->n_objects)
	{
		lray.o = mult_matrix_vertex(isec, scene->object[i].w2o);
		lray.dir = vector_diff(
				mult_matrix_vertex(light.pos, scene->object[i].w2o),
				lray.o);
		lray.t = 0;
		lray.t = scene->object[i].intersect(lray);
		if (lray.t > 0 && lray.t < 1 && scene->object[i].id != id)
			return (1);
		i++;
	}
	return (0);
}

t_vector		shade(t_scene *scene, t_object hit, t_ray ray, float t)
{
	t_vector	color;
	t_vertex	isec;
	t_vector	normal;
	int			i;

	color = new_vector(0, 0, 0);
	isec = vector_sum(mult_vector(ray.dir, t), ray.o);
	normal = hit.get_normal(isec);
	if (dot_product(normalize(ray.dir), normalize(normal)) > 0)
			normal = mult_vector(normal, -1);
	isec = mult_matrix_vertex(isec, hit.o2w);
	normal = mult_matrix_vector(normal, hit.no2w);
	i = 0;
	while (i < scene->n_lights)
	{
		if (!get_shadow(scene, scene->light[i], isec, hit.id))
		{
			color = color_lerp(color, hit.color,
					get_light(scene->light[i], isec, normal));
		}
		i++;
	}
	return (color);
}

