/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trans_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 11:18:09 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/11 14:31:29 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
** 00 01 02 03
** 10 11 12 13
** 20 21 22 23
** 30 31 32 33
*/
t_matrix		get_trans_matrix(float tx, float ty, float tz)
{
	t_matrix	new;

	new = get_identity_matrix();
	new.m[0][3] = tx;
	new.m[1][3] = ty;
	new.m[2][3] = tz;
	return (new);
}
