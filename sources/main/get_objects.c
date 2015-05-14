/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:14:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/14 14:13:06 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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
	t_object	c1;
	t_object	c2;
	t_object	c3;
	t_object	c4;
	t_object	c01;

	/* Spheres */
	s1 = new_sphere(new_vector(-350, 0, -450), 100);
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
	/* Cylinders */
	c1 = new_cylinder(new_vector(-300, 0, -440), 15, new_vector(10, 0, 25));
	c1.color = new_color(100, 25, 150);
	c2 = new_cylinder(new_vector(0, 150, -700), 50, new_vector(0, 0, 90));
	c2.color = new_color(100, 25, 150);
	c3 = new_cylinder(new_vector(0, 0, -700), 50, new_vector(0, 0, 90));
	c3.color = new_color(100, 25, 150);
	c4 = new_cylinder(new_vector(0, -150, -700), 50, new_vector(0, 0, 90));
	c4.color = new_color(100, 25, 150);
	/* Cones */
	c01 = new_cone(new_vector(0, 0, -600), 0.5, new_vector(0, 0, 10));
	c01.color = new_color(111, 0, 255);
	scene.n_objects = 11;
	scene.object[0] = s1;
	scene.object[1] = p1;
	scene.object[2] = p2;
	scene.object[3] = p3;
	scene.object[4] = p4;
	scene.object[5] = p5;
	scene.object[6] = c1;
	scene.object[7] = c2;
	scene.object[8] = c3;
	scene.object[9] = c4;
	scene.object[10] = c01;
	return (scene);
}
