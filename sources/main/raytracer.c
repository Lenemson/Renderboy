/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:17:28 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/26 14:36:13 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "intersect.h"

static int		process(t_scene *scene, int x, int y)
{
	int			i;
	t_ray		ray;
	t_vector	dir;

	dir = vector_diff(scene->camera.viewplane_current, scene->camera.pos);
	dir = normalize(dir);
	ray = new_ray(scene->camera.pos, dir);
	i = 0;
	while (i < scene->n_objects)
	{
		if (((t_sphere *) (scene->objects[i]))->type == 1
				&& intersect_sphere(ray, (t_sphere *) scene->objects[i]))
			render(scene->gfx, x, y);
		i++;
	}
	return (0);
}

int				raytracer(t_scene *scene)
{
	int			x;
	int			y;
	t_vector	up;
	t_vector	right;
	t_camera	camera;

	x = 0;
	y = 0;
	camera = scene->camera;
	while (y < scene->camera.res_y)
	{
		up = mult_vector(camera.up, (float) y * camera.y_indent);
		while (x < scene->camera.res_x)
		{
			right = mult_vector(camera.right, (float) x * camera.x_indent);
			camera.viewplane_current = vector_sum(camera.viewplane, right);
			camera.viewplane_current = vector_diff(camera.viewplane_current, up);
			scene->camera = camera;
			if (process(scene, x, y) == 1)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
