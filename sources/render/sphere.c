/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:46:47 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/04 14:41:04 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float			intersect_sphere(t_object const object, t_ray const ray)
{
	float		t;
	t_vector	rs;
	float		a;
	float		b;
	float		c;

	rs = vector_diff(ray.o, object.pos);
	a = dot_product(ray.dir, ray.dir);
	b = 2 * dot_product(ray.dir, rs);
	c = dot_product(rs, rs) - object.shape.sphere.sqr_radius;
	t = solve_quadratic(a, b, c);
	return (t);
}
