/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/24 18:33:41 by jibanez          ###   ########.fr       */
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

	dir = vector_diff(camera.viewplane, camera.pos);
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
			printf("(%d,%d)\n", x, y);///
			right = mult_vector(camera.right, (float) x * camera.x_indent);
			camera.viewplane = vector_sum(camera.viewplane, right);
			camera.viewplane = vector_diff(camera.viewplane, up);
			printf("(%f,%f)\n", camera.viewplane.x, camera.viewplane.y);///
			if (process(camera) == 1)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

static t_camera	init_camera(t_camera camera, float res_x, float res_y)
{
	camera = get_new_camera(800, 600);
	camera = set_fov(camera, 60);
	camera = set_indent(camera, res_x, res_y);
	camera = set_camera_pos(camera, 0, 0, 0);
	camera.viewplane = get_viewplane_pos(camera);
	return (camera);
}

int				main(void)
{
	t_camera	camera;

	camera = init_camera(camera, SCR_WIDTH, SCR_HEIGHT);
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
