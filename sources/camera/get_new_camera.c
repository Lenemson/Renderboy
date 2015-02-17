/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:22:13 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/17 15:16:26 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera		get_new_camera(int width, int height, float fov)
{
	t_camera	camera;

	camera.viewplane_width = width;
	camera.viewplane_height = height;
	camera.view_distance = 0.0;
	camera = set_fov(camera, fov);
	camera.pos_x = 0;
	camera.pos_y = 0;
	camera.pos_z = 0;
	camera.forward.x = 0;
	camera.forward.y = 0;
	camera.forward.z = -1;
	camera.forward = normalize(camera.forward);
	return (camera);
}
