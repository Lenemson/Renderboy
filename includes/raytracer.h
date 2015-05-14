/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:32:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/14 13:42:03 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "render.h"

t_scene			get_objects(t_scene scene);
t_object		new_sphere(t_vertex pos, float radius);
t_object		new_plane(t_vertex pos, float ax, float ay, float az);
t_object		new_cylinder(t_vertex pos, float radius, t_vector rot);
t_object		new_cone(t_vertex pos, float radius, t_vector rot);

#endif
