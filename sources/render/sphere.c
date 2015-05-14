/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:46:47 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/13 14:14:59 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float			intersect_sphere(t_object const object, t_ray const ray)
{
	float		t;
	float		a;
	float		b;
	float		c;

	(void) object;
	a = dot_product(ray.dir, ray.dir);
	b = 2 * dot_product(ray.dir, ray.o);
	c = dot_product(ray.o, ray.o) - 1;
	t = solve_quadratic(a, b, c);
	return (t);
}
