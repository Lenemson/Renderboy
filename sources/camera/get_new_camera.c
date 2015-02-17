/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:22:13 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/17 16:48:37 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera		get_new_camera(int width, int height)
{
	t_camera	camera;

	camera.viewplane_width = width;
	camera.viewplane_height = height;
	camera.view_distance = 0;
	camera.pos.x = 0;
	camera.pos.y = 0;
	camera.pos.z = 0;
	camera.forward.x = 0;
	camera.forward.y = 0;
	camera.forward.z = 1;
	camera.forward = normalize(camera.forward);
	camera.up.x = 0;
	camera.up.y = 1;
	camera.up.z = 0;
	camera.up = normalize(camera.up);
	camera.right.x = 1;
	camera.right.y = 0;
	camera.right.z = 0;
	camera.right = normalize(camera.right);
	return (camera);
}
