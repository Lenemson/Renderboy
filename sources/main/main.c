/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/18 14:01:46 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"
#include <stdio.h>/////

static t_camera		init_camera(t_camera camera)
{
	camera = get_new_camera(2, 2, 60);
	camera = set_camera_pos(camera, 0, 0, 0);
	camera.viewplane = get_viewplane_pos(camera);
	return (camera);
}

int					main(void)
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
	return (0);
}
