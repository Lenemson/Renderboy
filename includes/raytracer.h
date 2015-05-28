/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:32:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/28 14:40:25 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "render.h"

t_scene			get_objects(t_scene scene, char *scene_file);
t_object		get_sphere(char **object, int id);
t_object		new_sphere(t_vertex pos, float radius);
t_object		get_plane(char **object, int id);
t_object		new_plane(t_vertex pos, float ax, float ay, float az);
t_object		get_cylinder(char **object, int id);
t_object		new_cylinder(t_vertex pos, float radius, t_vector rot);
t_object		get_cone(char **object, int id);
t_object		new_cone(t_vertex pos, float radius, t_vector rot);
void			free_tab(char **tab);

#endif
