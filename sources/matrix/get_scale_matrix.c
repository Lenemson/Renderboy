/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 11:32:12 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/11 14:26:46 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
** 00 01 02 03
** 10 11 12 13
** 20 21 22 23
** 30 31 32 33
*/
t_matrix		get_scale_matrix(float scale_x, float scale_y, float scale_z)
{
	t_matrix	new;

	new = get_identity_matrix();
	new.m[0][0] = scale_x;
	new.m[1][1] = scale_y;
	new.m[2][2] = scale_z;
	return (new);
}
