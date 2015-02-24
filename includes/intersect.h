/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:45:56 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/24 15:52:12 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "ray.h"

struct			s_sphere
{
	t_vertex	center;
	float		radius;
};

typedef struct s_sphere	t_sphere;


int				intersect_sphere(t_ray ray, t_sphere sphere);

#endif
