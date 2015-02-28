/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:14:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/28 14:24:31 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "intersect.h"
#include "raytracer.h"

t_scene			get_objects(t_scene scene)
{
	t_sphere	*s1;
	t_sphere	*s2;

	s1 = malloc(sizeof(t_sphere));
	s1->type = 1;
	s1->center = new_vector(400, 55, -1000);
	s1->radius = 100;
	s1->sqr_radius = 100 * 100;
	s2 = malloc(sizeof(t_sphere));
	s2->type = 1;
	s2->center = new_vector(-200, -55, -2000);
	s2->radius = 50;
	s2->sqr_radius = 50 * 50;
	scene.n_objects = 2;
	scene.objects[0] = (void *) s1;
	scene.objects[1] = (void *) s2;
	scene.objects[2] = NULL;
	return (scene);
}
