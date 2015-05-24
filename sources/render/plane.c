/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:03:57 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/24 11:30:01 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float		intersect_plane(t_ray const ray)
{
	float	b;
	float	c;

	b = ray.dir.z;
	c = -(ray.o.z);
	return (c / b);
}

t_vector	plane_normal(t_vertex const p)
{
	t_vector	normal;

	(void)p;
	normal.x = 0;
	normal.y = 0;
	normal.z = 1;
	return (normal);
}
