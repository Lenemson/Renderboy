/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/26 11:24:34 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>/////

int				main(void)
{
	t_scene		scene;

	scene.camera = get_new_camera(SCR_WIDTH, SCR_HEIGHT, 60);
	scene.gfx = init_gfx(SCR_WIDTH, SCR_HEIGHT, "raytracer");
	printf("viewplaneWidth=%f,viewplaneHeight=%f\n", scene.camera.viewplane_width,
			scene.camera.viewplane_height);////
	printf("viewDistance=%f\n", scene.camera.view_distance);////
	printf("xIndent=%f, yIndent=%f\n", scene.camera.x_indent,
			scene.camera.y_indent);///
	printf("Camera Pos:\n");
	printf("x=%f\ny=%f\nz=%f\n", scene.camera.pos.x, scene.camera.pos.y,
			scene.camera.pos.z);
	printf("Viewplane UpLeft:\n");
	printf("x=%f\ny=%f\nz=%f\n", scene.camera.viewplane.x,
			scene.camera.viewplane.y, scene.camera.viewplane.z);
	raytracer(scene, SCR_WIDTH, SCR_HEIGHT);
	return (0);
}
