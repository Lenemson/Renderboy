/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 15:00:00 by jibanez           #+#    #+#             */
/*   Updated: 2015/04/02 11:29:59 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix		matrix_product(t_matrix const m1, t_matrix const m2)
{
	t_matrix	m3;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			m3.m[i][j] = m1.m[i][0] * m2.m[0][j]
					   + m1.m[i][1] * m2.m[1][j]
					   + m1.m[i][2] * m2.m[2][j]
					   + m1.m[i][3] * m2.m[3][j];
			j++;
		}
		i++;
	}
	return (m3);
}
