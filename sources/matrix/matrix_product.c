/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 15:00:00 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/23 17:31:37 by jibanez          ###   ########.fr       */
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
			m3.c[i][j] = m1.c[i][0] * m2.c[0][j]
					   + m1.c[i][1] * m2.c[1][j]
					   + m1.c[i][2] * m2.c[2][j]
					   + m1.c[i][3] * m2.c[3][j];
			j++;
		}
		i++;
	}
	return (m3);
}
