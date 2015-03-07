/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:14:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/07 16:58:28 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "render.h"
#include "raytracer.h"

t_scene			get_objects(t_scene scene)
{
	t_object	s1;
	t_object	s2;
	t_object	p1;
	t_object	p2;
	t_object	p3;
	t_object	p4;

	s1.pos = new_vector(-200, 0, -600);
	s1.shape.sphere.radius = 100;
	s1.shape.sphere.sqr_radius = 100 * 100;
	s1.color = new_color(0, 50, 160);
	s1.intersect = intersect_sphere;
	s2.pos = new_vector(-200, -100, -2000);
	s2.shape.sphere.radius = 200;
	s2.shape.sphere.sqr_radius = 200 * 200;
	s2.color = new_color(160, 0, 50);
	s2.intersect = intersect_sphere;
	p1.pos = new_vector(0, -100, 0);
	p1.shape.plane.normal = new_vector(0, 1, 0);
	p1.color = new_color(130, 190, 222);
	p1.intersect = intersect_plane;
	p2.pos = new_vector(-200, 0, 0);
	p2.shape.plane.normal = new_vector(1, 0, 0);
	p2.color = new_color(111, 222, 222);
	p2.intersect = intersect_plane;
	p3.pos = new_vector(200, 0, 0);
	p3.shape.plane.normal = new_vector(-1, 0, 0);
	p3.color = new_color(111, 222, 222);
	p3.intersect = intersect_plane;
	p4.pos = new_vector(0, 100, 0);
	p4.shape.plane.normal = new_vector(0, -1, 0);
	p4.color = new_color(200, 50, 0);
	p4.intersect = intersect_plane;
	scene.n_objects = 6;
	scene.object[0] = s1;
	scene.object[1] = s2;
	scene.object[2] = p1;
	scene.object[3] = p2;
	scene.object[4] = p3;
	scene.object[5] = p4;
	return (scene);
}
