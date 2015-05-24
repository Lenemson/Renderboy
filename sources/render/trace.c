/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:09:01 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/24 13:03:54 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#define LIMIT 1000000000

t_vector		trace(t_scene *scene, t_ray const ray)
{
	t_object	hit;
	t_ray		o_ray;
	float		t;
	int			i;

	i = 0;
	t = LIMIT;
	while (i < scene->n_objects)
	{
		o_ray.t =
			scene->object[i].intersect(mult_matrix_ray(ray,
						scene->object[i].w2o));
		if (o_ray.t > 0 && o_ray.t < t)
		{
			hit = scene->object[i];
			t = o_ray.t;
			o_ray = mult_matrix_ray(ray, scene->object[i].w2o);
		}
		i++;
	}
	if (t < LIMIT)
		return (shade(scene, hit, o_ray, t));
	else
		return (new_color(0, 0, 0));
}
