/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:15:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/17 17:18:14 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	set_camera_pos(t_camera camera, int x, int y, int z)
{
	camera.pos.x = x;
	camera.pos.y = y;
	camera.pos.z = z;
	return (camera);
}
