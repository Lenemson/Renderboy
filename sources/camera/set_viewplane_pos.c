/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_viewplane_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:47:37 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/25 10:55:29 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/*
** Set the 3D world position of the viewplane upper left pixel
*/

t_camera		set_viewplane_pos(t_camera camera)
{
	t_vector	forward_transform;
	t_vector	up_transform;
	t_vector	right_transform;

	camera.viewplane.x = camera.pos.x;
	camera.viewplane.y = camera.pos.y;
	camera.viewplane.z = camera.pos.z;
	forward_transform = mult_vector(camera.forward, camera.view_distance);
	up_transform = mult_vector(camera.up, camera.viewplane_height / 2.0);
	right_transform = mult_vector(camera.right, camera.viewplane_width / 2.0);
	camera.viewplane = vector_sum(camera.viewplane, forward_transform);
	camera.viewplane = vector_sum(camera.viewplane, up_transform);
	camera.viewplane = vector_diff(camera.viewplane, right_transform);
	camera.viewplane_current = camera.viewplane;
	return (camera);
}
