/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:17:28 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/26 11:50:24 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "intersect.h"

static int		process(t_scene scene)
{
	t_ray		ray;
	t_vector	dir;
	t_sphere	s;

	s.center = new_vector(0, 0, -300);
	s.radius = 100;
	s.sqr_radius = 100 * 100;
	dir = vector_diff(scene.camera.viewplane_current, scene.camera.pos);
	dir = normalize(dir);
	ray = new_ray(scene.camera.pos, dir);
	if (intersect_sphere(ray, s))
	{
		// RENDER(x, y)
	}
	return (0);
}

int				raytracer(t_scene scene, int res_x, int res_y)
{
	int			x;
	int			y;
	t_vector	up;
	t_vector	right;
	t_camera	camera;

	x = 0;
	y = 0;
	camera = scene.camera;
	while (y < res_y)
	{
		up = mult_vector(camera.up, (float) y * camera.y_indent);
		while (x < res_x)
		{
			right = mult_vector(camera.right, (float) x * camera.x_indent);
			camera.viewplane_current = vector_sum(camera.viewplane, right);
			camera.viewplane_current = vector_diff(camera.viewplane_current, up);
			scene.camera = camera;
			if (process(scene) == 1)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
