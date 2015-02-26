/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:32:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/26 14:20:44 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "render.h"

struct					s_scene
{
	t_env				gfx;
	t_camera			camera;
	int					n_objects;
	void				*objects[100];
};

typedef struct s_scene	t_scene;

t_scene			get_objects(t_scene scene);
int				raytracer(t_scene *scene);

#endif
