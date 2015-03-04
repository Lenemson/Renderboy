/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:03:57 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/04 13:01:56 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

t_result		solve_quadratic(float a, float b, float c)
{
	t_result	res;
	float		discr;
	float		q;

	res.n = 0;
	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (res);
	else if (discr == 0)
	{
		res.t0 = (-0.5 * b) / a;
		res.n = 1;
	}
	else
	{
		q = (b > 0 ? (b + sqrt(discr)) : (b - sqrt(discr)));
		q *= -0.5;
		res.t0 = q / a;
		res.t1 = c / q;
		res.n = 2;
	}
	return (res);
}
