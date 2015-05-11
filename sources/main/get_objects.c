/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:14:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/11 16:36:52 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "render.h"
#include "raytracer.h"

t_scene			get_objects(t_scene scene)
{
	t_object	one;
	t_object	two;

	one = new_sphere(new_vector(0, 0, -300), 100, new_color(100, 255, 255));
	two = new_sphere(new_vector(-100, 40, -350), 150, new_color(255, 5, 55));
	scene.n_objects = 2;
	scene.object[0] = one;
	scene.object[1] = two;
	return (scene);
}
