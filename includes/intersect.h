/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:45:56 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/26 14:29:24 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "ray.h"

struct			s_result
{
	int			n;
	float		t0;
	float		t1;
};

struct			s_sphere
{
	int			type;
	t_vertex	center;
	float		radius;
	float		sqr_radius;
};

typedef struct s_sphere	t_sphere;
typedef struct s_result	t_result;


int				intersect_sphere(t_ray ray, t_sphere *sphere);
t_result		solve_quadratic(float a, float b, float c);

#endif
