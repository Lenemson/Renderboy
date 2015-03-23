/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 15:11:58 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/23 17:31:18 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct s_matrix	t_matrix;

struct	s_matrix
{
	float	c[4][4];
};

t_matrix	matrix_product(t_matrix const m1, t_matrix const m2);
t_vertex	mult_matrix_vertex(t_vertex const src, t_matrix const m);
t_vector	mult_matrix_vector(t_vector const src, t_matrix const m);

#endif
