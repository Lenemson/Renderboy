/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:14:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/14 10:17:09 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "render.h"
#include "raytracer.h"

t_scene			get_objects(t_scene scene)
{
	t_object	s1;
	t_object	p1;
	t_object	p2;
	t_object	p3;
	t_object	p4;
	t_object	p5;

	/* Spheres */
	s1 = new_sphere(new_vector(-300, -300, -800), 100);
	s1.color = new_color(255, 255, 255);
	/* Planes */
	p1 = new_plane(new_vector(-300, 0, -100), 0, 90, 0);
	p1.color = new_color(0, 255, 0);
	p2 = new_plane(new_vector(300, 0, -100), 0, -90, 0);
	p2.color = new_color(0, 255, 0);
	p3 = new_plane(new_vector(0, 0, -800), 0, 0, 0);
	p3.color = new_color(0, 255, 255);
	p4 = new_plane(new_vector(0, 300, 0), 90, 0, 0);
	p4.color = new_color(255, 255, 0);
	p5 = new_plane(new_vector(0, -300, 0), -90, 0, 0);
	p5.color = new_color(255, 255, 0);
	scene.n_objects = 6;
	scene.object[0] = s1;
	scene.object[1] = p1;
	scene.object[2] = p2;
	scene.object[3] = p3;
	scene.object[4] = p4;
	scene.object[5] = p5;
	return (scene);
}
