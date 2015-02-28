/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:07:26 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/28 15:08:00 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int				render(t_scene *scene)
{
	int			x;
	int			y;
	t_vector	up;
	t_vector	right;
	t_camera	camera;
	t_ray		ray;

	x = 0;
	y = 0;
	camera = scene->camera;
	while (y < scene->camera.res_y)
	{
		up = mult_vector(camera.up, (float) y * camera.y_indent);
		while (x < scene->camera.res_x)
		{
			right = mult_vector(camera.right, (float) x * camera.x_indent);
			ray = construct_ray(camera, up, right);
			put_pixel(scene->gfx, x, y, trace(ray, scene->objects));
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
