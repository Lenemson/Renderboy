/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:07:26 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/15 14:41:39 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int				render(t_scene *scene)
{
	int			x;
	int			y;
	t_vector	up;
	t_ray		ray;

	x = 0;
	y = 0;
	while (y < scene->camera.res_y)
	{
		up = mult_vector(scene->camera.up, (float)y * scene->camera.y_indent);
		while (x < scene->camera.res_x)
		{
			ray = construct_ray(scene->camera, up, x);
			put_pixel(scene->gfx, x, y,
					trace(scene->object, scene->n_objects, ray));
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
