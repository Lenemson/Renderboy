/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:22:13 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/25 11:16:37 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	get_new_camera(float res_x, float res_y, float fov)
{
	t_camera	camera;

	camera.pos.x = 0;
	camera.pos.y = 0;
	camera.pos.z = 0;
	camera.forward = new_vector(0, 0, -1);
	camera.up = new_vector(0, 1, 0);
	camera.right = new_vector(1, 0, 0);
	camera.viewplane_width = 2 * (res_x / res_y);
	camera.viewplane_height = 2;
	camera = set_fov(camera, fov);
	camera.x_indent = camera.viewplane_width / res_x;
	camera.y_indent = camera.viewplane_height / res_y;
	return (camera);
}
