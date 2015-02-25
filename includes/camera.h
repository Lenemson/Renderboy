/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 13:20:45 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/25 11:19:26 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

# define SCR_WIDTH 800
# define SCR_HEIGHT 600

struct			s_camera
{
	t_vertex	pos;
	t_vector	forward;
	t_vector	up;
	t_vector	right;
	float		viewplane_width;
	float		viewplane_height;
	float		view_distance;
	t_vertex	viewplane;
	t_vertex	viewplane_current;
	float		x_indent;
	float		y_indent;
};

typedef struct s_camera	t_camera;

t_camera		get_new_camera(float res_x, float res_y, float fov);
t_camera		set_fov(t_camera camera, float fov);
t_camera		set_camera_pos(t_camera camera, int x, int y, int z);
t_camera		set_viewplane_pos(t_camera camera);

#endif
