/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 11:49:26 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/14 13:58:55 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrix.h"
#define PI 3.14159265

#include <stdio.h>//////

/*
** 00 01 02 03
** 10 11 12 13
** 20 21 22 23
** 30 31 32 33
*/
static	t_matrix	rot_x_matrix(float rot_x)
{
	t_matrix		r;

	r = get_identity_matrix();
	rot_x = rot_x * (PI / 180.0);
	r.m[1][1] = cos(rot_x);
	r.m[1][2] = -sin(rot_x);
	r.m[2][1] = sin(rot_x);
	r.m[2][2] = cos(rot_x);
	return (r);
}

static	t_matrix	rot_y_matrix(float rot_y)
{
	t_matrix		r;

	r = get_identity_matrix();
	rot_y = rot_y * (PI / 180.0);
	r.m[0][0] = cos(rot_y);
	r.m[0][2] = sin(rot_y);
	r.m[2][0] = -sin(rot_y);
	r.m[2][2] = cos(rot_y);
	return (r);
}

static	t_matrix	rot_z_matrix(float rot_z)
{
	t_matrix		r;

	r = get_identity_matrix();
	rot_z = rot_z * (PI / 180.0);
	r.m[0][0] = cos(rot_z);
	r.m[0][1] = -sin(rot_z);
	r.m[1][0] = sin(rot_z);
	r.m[1][1] = cos(rot_z);
	return (r);
}

t_matrix		get_rot_matrix(float rot_x, float rot_y, float rot_z)
{
	t_matrix	new;
	t_matrix	rx;
	t_matrix	ry;
	t_matrix	rz;

	rx = rot_x_matrix(rot_x);
	ry = rot_y_matrix(rot_y);
	rz = rot_z_matrix(rot_z);
	new = matrix_product(rx, ry);
	new = matrix_product(new, rz);

	/*
	printf("rot x\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%f    ", rx.m[i][j]);
		printf("\n");
	}
	printf("rot y\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%f    ", ry.m[i][j]);
		printf("\n");
	}
	printf("rot z\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%f    ", rz.m[i][j]);
		printf("\n");
	}
	printf("rot\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%f    ", new.m[i][j]);
		printf("\n");
	}
	printf("\n");*/

	return (new);
}

