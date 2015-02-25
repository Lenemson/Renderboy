/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:22:13 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/25 10:18:23 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	get_new_camera(float res_x, float res_y)
{
	t_camera	camera;

	camera.viewplane_width = res_x / res_y;
	camera.viewplane_height = 1;
	camera.view_distance = 0;
	camera.x_indent = 0;
	camera.y_indent = 0;
	camera.forward = new_vector(0, 0, 1);
	camera.up = new_vector(0, 1, 0);
	camera.right = new_vector(1, 0, 0);
	camera.pos.x = 0;
	camera.pos.y = 0;
	camera.pos.z = 0;
	camera.viewplane.x = 0;
	camera.viewplane.y = 0;
	camera.viewplane.z = 0;
	return (camera);
}
