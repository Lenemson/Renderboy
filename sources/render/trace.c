/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:09:01 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/11 16:09:59 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int			trace(t_object object[100], int const n, t_ray const ray)
{
	t_object	hit;
	t_ray		o_ray;
	float		t;
	float		tmp;
	int			i;

	i = 0;
	t = 1000000000;
	hit.color = new_color(0, 0, 0);
	while (i < n)
	{
		o_ray.o = mult_matrix_vertex(ray.o, object[i].w2o);
		o_ray.dir = mult_matrix_vector(ray.dir, object[i].w2o);
		tmp = object[i].intersect(object[i], o_ray);
		if (tmp > 0 && tmp < t)
		{
			t = tmp;
			hit = object[i];
		}
		i++;
	}
	return (hit.color.val);
}
