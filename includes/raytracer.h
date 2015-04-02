/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:32:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/04/02 12:12:36 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "render.h"

t_scene			get_objects(t_scene scene);
t_object		new_sphere(t_vertex pos, float radius, t_color color);

#endif
