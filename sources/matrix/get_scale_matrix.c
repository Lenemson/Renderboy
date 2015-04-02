/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 11:32:12 by jibanez           #+#    #+#             */
/*   Updated: 2015/04/02 11:48:05 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix		get_scale_matrix(float scale_x, float scale_y, float scale_z)
{
	t_matrix	new;

	new.m[0][0] = scale_x;
	new.m[0][1] = 0;
	new.m[0][2] = 0;
	new.m[0][3] = 0;
	new.m[1][0] = 0;
	new.m[1][1] = scale_y;
	new.m[1][2] = 0;
	new.m[1][3] = 0;
	new.m[2][0] = 0;
	new.m[2][1] = 0;
	new.m[2][2] = scale_z;
	new.m[2][3] = 0;
	new.m[3][0] = 0;
	new.m[3][1] = 0;
	new.m[3][2] = 0;
	new.m[3][3] = 1;
	return (new);
}
