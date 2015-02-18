/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:22:13 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/18 14:11:41 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	get_new_camera(float width, float height, float fov)
{
	t_camera	camera;

	camera.viewplane_width = width;
	camera.viewplane_height = height;
	camera = set_fov(camera, fov);
	camera.x_indent = width / (float) SCR_WIDTH;
	camera.y_indent = height / (float) SCR_HEIGHT;
	camera.pos.x = 0;
	camera.pos.y = 0;
	camera.pos.z = 0;
	camera.forward = new_vector(0, 0, 1);
	camera.up = new_vector(0, 1, 0);
	camera.right = new_vector(1, 0, 0);
	return (camera);
}
