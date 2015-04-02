/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trans_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 11:18:09 by jibanez           #+#    #+#             */
/*   Updated: 2015/04/02 11:24:53 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix		get_trans_matrix(float tx, float ty, float tz)
{
	t_matrix	new;

	new.m[0][0] = 1;
	new.m[0][1] = 0;
	new.m[0][2] = 0;
	new.m[0][3] = 0;
	new.m[1][0] = 0;
	new.m[1][1] = 1;
	new.m[1][2] = 0;
	new.m[1][3] = 0;
	new.m[2][0] = 0;
	new.m[2][1] = 0;
	new.m[2][2] = 1;
	new.m[2][3] = 0;
	new.m[3][0] = tx;
	new.m[3][1] = ty;
	new.m[3][2] = tz;
	new.m[3][3] = 1;
	return (new);
}
