/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/18 16:20:51 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"
#include "raytracer.h"
#include <stdio.h>/////

static int		process(t_camera camera)
{
	t_vector	dir;
	float		t;

	dir = vector_diff(camera.viewplane, camera.pos);
	dir = normalize(dir);
	//t = raycast(camera.pos, dir);
	(void)t;
	return (0);
}

static int		raytracer(t_camera camera, int width, int height)
{
	int			x;
	int			y;
	t_vector	up;
	t_vector	right;

	x = 0;
	y = 0;
	while (y < height)
	{
		up = mult_vector(camera.up, (float) y * camera.y_indent);
		while (x < width)
		{
			right = mult_vector(camera.right, (float) x * camera.x_indent);
			camera.viewplane = vector_sum(camera.viewplane, right);
			camera.viewplane = vector_diff(camera.viewplane, up);
			if (process(camera) == 1)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

static t_camera	init_camera(t_camera camera)
{
	camera = get_new_camera(2, 2);
	camera = set_fov(camera, 60);
	camera = set_indent(camera, SCR_WIDTH, SCR_HEIGHT);
	camera = set_camera_pos(camera, 0, 0, 0);
	camera.viewplane = get_viewplane_pos(camera);
	return (camera);
}

int				main(void)
{
	t_camera	camera;

	camera = init_camera(camera);
	printf("vpWidth=%f, vpHeight=%f\n", camera.viewplane_width,
			camera.viewplane_height);///
	printf("scrWidth=%d, scrHeight=%d\n", SCR_WIDTH, SCR_HEIGHT);
	printf("viewDistance=%f\n", camera.view_distance);////
	printf("xIndent=%f, yIndent=%f\n", camera.x_indent, camera.y_indent);///
	printf("Camera Pos:\n");
	printf("x=%f\ny=%f\nz=%f\n", camera.pos.x, camera.pos.y, camera.pos.z);
	printf("Viewplane UpLeft:\n");
	printf("x=%f\ny=%f\nz=%f\n", camera.viewplane.x,
			camera.viewplane.y, camera.viewplane.z);
	raytracer(camera, 800, 600);
	return (0);
}
