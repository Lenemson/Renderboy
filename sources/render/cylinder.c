/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 11:05:17 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/24 13:13:33 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

float		intersect_cylinder(t_ray const ray)
{
	float	a;
	float	b;
	float	c;

	a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	b = (2 * ray.o.x * ray.dir.x) + (2 * ray.o.z * ray.dir.z);
	c = pow(ray.o.x, 2) + pow(ray.o.z, 2) - 1;
	return (solve_quadratic(a, b, c));
}

t_vector	cylinder_normal(t_vertex const p)
{
	t_vector	normal;

	normal.x = p.x;
	normal.y = 0;
	normal.z = p.z;
	return (normal);
}
