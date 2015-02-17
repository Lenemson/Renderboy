/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_viewplane_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 13:32:38 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/17 17:01:59 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/*
** Return the 3D world position of the viewplane upper left pixel
*/

t_vertex	get_viewplane_pos(t_camera camera)
{
	t_vertex	viewplane;
	t_vector	forward_transform;
	t_vector	up_transform;
	t_vector	right_transform;

	viewplane.x = camera.pos.x;
	viewplane.y = camera.pos.y;
	viewplane.z = camera.pos.z;
	forward_transform = mult_vector(camera.forward, camera.view_distance);
	up_transform = mult_vector(camera.up, camera.viewplane_height / 2.0);
	right_transform = mult_vector(camera.right, camera.viewplane_width / 2.0);
	viewplane = vector_sum(viewplane, forward_transform);
	viewplane = vector_sum(viewplane, up_transform);
	viewplane = vector_diff(viewplane, right_transform);
	return (viewplane);
}
