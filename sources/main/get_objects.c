/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:14:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/24 16:20:44 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "render.h"
#include "raytracer.h"

t_scene			get_objects(t_scene scene)
{
	t_light		a;
	t_object	b;
	t_object	c;
	t_object	d;
	t_object	e;
	t_object	f;
	//t_light		g;

	/* Lights */
	a.pos = new_vector(0, 0, 0);
	a.color = new_color(255, 255, 255);
	//g.pos = new_vector(200, 300, 0);
	//g.color = new_color(255, 255, 255);
	/**/
	scene.n_lights = 1;
	scene.light[0] = a;
	//scene.light[1] = g;
	/* Spheres */
	b = new_sphere(new_vector(0, 0, -400), 100);
	b.color = new_color(170, 57, 57);
	b.diffuse_color = new_vector(1, 1, 1);
	/* Planes */
	c = new_plane(new_vector(0, 0, -500), 0, 0, 0);
	c.color = new_color(34, 102, 102);
	c.diffuse_color = new_vector(1, 1, 1);
	d = new_plane(new_vector(0, -100, 0), 90, 0, 0);
	d.color = new_color(34, 102, 102);
	d.diffuse_color = new_vector(1, 1, 1);
	/* Cylinders */
	e = new_cylinder(new_vector(-200, 0, -300), 25, new_vector(0, 0, 30));
	e.color = new_color(170, 132, 57);
	e.diffuse_color = new_vector(1, 1, 1);
	/* Cones */
	f = new_cone(new_vector(200, 0, -400), 0.5, new_vector(0, 0, 30));
	f.color = new_color(170, 132, 57);
	f.diffuse_color = new_vector(1, 1, 1);
	/**/
	scene.n_objects = 5;
	scene.object[0] = b;
	scene.object[1] = c;
	scene.object[2] = d;
	scene.object[3] = e;
	scene.object[4] = f;
	return (scene);
}
