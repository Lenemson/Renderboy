/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:46:47 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/04 13:02:08 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		intersect_sphere(t_ray ray, t_sphere *sphere)
{
	t_result	res;
	t_vector	rs;
	float		a;
	float		b;
	float		c;

	rs = vector_diff(ray.o, sphere->center);
	a = dot_product(ray.dir, ray.dir);
	b = 2 * dot_product(ray.dir, rs);
	c = dot_product(rs, rs) - sphere->sqr_radius;
	res = solve_quadratic(a, b, c);
	if (res.n == 0)
		return (0);
	return (1);
}
