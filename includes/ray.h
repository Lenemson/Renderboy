/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 17:02:09 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/18 17:05:16 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

struct			s_ray
{
	t_vertex	o;
	t_vector	dir;
	float		t;
};

typedef struct s_ray	t_ray;

t_ray			new_ray(t_vertex o, t_vector dir);

#endif
