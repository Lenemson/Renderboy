/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:03:57 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/21 16:08:15 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float		intersect_plane(t_object const object, t_ray const ray)
{
	float	t;
	float	a;
	float	b;

	a = dot_product(vector_diff(object.pos, ray.o), object.shape.plane.normal);
	b = dot_product(ray.dir, object.shape.plane.normal);
	t = a / b;
	if (t > 0)
		return (t);
	else
		return (-1);
}
