/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 13:20:45 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/17 15:11:44 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

struct			s_camera
{
	int			viewplane_width;
	int			viewplane_height;
	float		view_distance;
	int			pos_x;
	int			pos_y;
	int			pos_z;
	t_vector	forward;
};

typedef struct s_camera	t_camera;

t_camera		get_new_camera(int width, int height, float fov);
t_camera		set_fov(t_camera camera, float fov);

#endif
