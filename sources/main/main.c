/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/25 12:32:04 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"
#include "ray.h"
#include <stdio.h>/////

static int		process(t_camera camera)
{
	t_ray		ray;
	t_vector	dir;
	float		t;

	dir = vector_diff(camera.viewplane_current, camera.pos);
	dir = normalize(dir);
	ray = new_ray(camera.pos, dir);
	(void)ray;
	// RAYCAST // t = raycast(camera.pos, dir);
	// RENDER
	(void)t;
	return (0);
}

static int		raytracer(t_camera camera, int res_x, int res_y)
{
	int			x;
	int			y;
	t_vector	up;
	t_vector	right;

	x = 0;
	y = 0;
	while (y < res_y)
	{
		up = mult_vector(camera.up, (float) y * camera.y_indent);
		while (x < res_x)
		{
			right = mult_vector(camera.right, (float) x * camera.x_indent);
			camera.viewplane_current = vector_sum(camera.viewplane, right);
			camera.viewplane_current = vector_diff(camera.viewplane_current, up);
			printf("(%d,%d) ", x, y);///
			printf("(%f,%f)\n", camera.viewplane_current.x,
					camera.viewplane_current.y);///
			if (process(camera) == 1)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int				main(void)
{
	t_camera	camera;

	camera = get_new_camera(SCR_WIDTH, SCR_HEIGHT, 60);
	printf("viewplaneWidth=%f,viewplaneHeight=%f\n", camera.viewplane_width,
			camera.viewplane_height);////
	printf("viewDistance=%f\n", camera.view_distance);////
	printf("xIndent=%f, yIndent=%f\n", camera.x_indent, camera.y_indent);///
	printf("Camera Pos:\n");
	printf("x=%f\ny=%f\nz=%f\n", camera.pos.x, camera.pos.y, camera.pos.z);
	printf("Viewplane UpLeft:\n");
	printf("x=%f\ny=%f\nz=%f\n", camera.viewplane.x,
			camera.viewplane.y, camera.viewplane.z);
	raytracer(camera, SCR_WIDTH, SCR_HEIGHT);
	return (0);
}
