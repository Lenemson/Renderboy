/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:17:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/18 16:21:14 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	set_indent(t_camera camera, float res_x, float res_y)
{
	camera.x_indent = camera.viewplane_width / res_x;
	camera.y_indent = camera.viewplane_height / res_y;
	return (camera);
}
