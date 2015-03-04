/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:03:57 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/04 15:42:44 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

float			solve_quadratic(float a, float b, float c)
{
	float		t0;
	float		t1;
	float		discr;
	float		q;

	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (-1);
	else if (discr == 0)
		return ((-0.5 * b) / a);
	else
	{
		q = (b > 0 ? (b + sqrt(discr)) : (b - sqrt(discr)));
		q *= -0.5;
		t0 = q / a;
		t1 = c / q;
	}
	if (t0 > 0 && t1 > 0)
		return (t0 < t1 ? t0 : t1);
	else if (t0 > 0)
		return (t0);
	else if (t1 > 0)
		return (t1);
	return (-1);
}
