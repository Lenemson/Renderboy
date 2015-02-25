/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:48:12 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/18 13:00:41 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

struct		s_vector
{
	float	x;
	float	y;
	float	z;
};

typedef struct s_vector	t_vector;
typedef struct s_vector	t_vertex;

t_vector	vector_sum(const t_vector a, const t_vector b);
t_vector	vector_diff(const t_vector a, const t_vector b);
t_vector	mult_vector(const t_vector v, const float n);
t_vector	div_vector(const t_vector v, const float n);
t_vector	normalize(t_vector v);
t_vector	cross_product(const t_vector a, const t_vector b);
t_vector	new_vector(const float x, const float y, const float z);

float		magnitude(const t_vector v);
float		squared_magnitude(const t_vector v);
float		dot_product(const t_vector a, const t_vector b);

#endif
