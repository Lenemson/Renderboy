/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:14:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/04 15:51:59 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "render.h"
#include "raytracer.h"

t_scene			get_objects(t_scene scene)
{
	t_object	s1;
	t_object	s2;

	s1.pos = new_vector(400, 55, -1000);
	s1.shape.sphere.radius = 100;
	s1.shape.sphere.sqr_radius = 100 * 100;
	s1.color = 0x00FF00;
	s1.intersect = intersect_sphere;
	s2.pos = new_vector(-200, -55, -2000);
	s2.shape.sphere.radius = 50;
	s2.shape.sphere.sqr_radius = 50 * 50;
	s2.color = 0xFF0000;
	s2.intersect = intersect_sphere;
	scene.n_objects = 2;
	scene.object[0] = s1;
	scene.object[1] = s2;
	return (scene);
}
