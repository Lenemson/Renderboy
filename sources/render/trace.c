/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:09:01 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/04 16:15:27 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int			trace(t_object object[100], int const n, t_ray const ray)
{
	t_object	hit;
	float		t;
	float		tmp;
	int			i;

	i = 0;
	t = 1000000000;
	hit.color = 0x000000;
	while (i < n)
	{
		tmp = object[i].intersect(object[i], ray);
		if (tmp > 0 && tmp < t)
		{
			t = tmp;
			hit = object[i];
		}
		i++;
	}
	return (hit.color);
}
