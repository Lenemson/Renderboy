/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 15:11:58 by jibanez           #+#    #+#             */
/*   Updated: 2015/04/02 11:48:27 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct s_matrix	t_matrix;

struct	s_matrix
{
	float	m[4][4];
};

t_matrix	matrix_product(t_matrix const m1, t_matrix const m2);

t_matrix	get_trans_matrix(float tx, float ty, float tz);
t_matrix	get_scale_matrix(float scale_x, float scale_y, float scale_z);

t_vertex	mult_matrix_vertex(t_vertex const src, t_matrix const m);
t_vector	mult_matrix_vector(t_vector const src, t_matrix const m);

#endif
