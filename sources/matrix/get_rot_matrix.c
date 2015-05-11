/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 11:49:26 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/10 15:04:48 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrix.h"
#define PI 3.14159265

#include <stdio.h>//////

static	t_matrix	rot_x_matrix(float rot_x)
{
	t_matrix		r;

	rot_x = ((rot_x / 2) * PI) / 180.0;
	r.m[0][0] = 1;
	r.m[0][1] = 0;
	r.m[0][2] = 0;
	r.m[0][3] = 0;
	r.m[1][0] = 0;
	r.m[1][1] = cos(rot_x);
	r.m[1][2] = sin(rot_x);
	r.m[1][3] = 0;
	r.m[2][0] = 0;
	r.m[2][1] = -sin(rot_x);
	r.m[2][2] = cos(rot_x);
	r.m[2][3] = 0;
	r.m[3][0] = 0;
	r.m[3][1] = 0;
	r.m[3][2] = 0;
	r.m[3][3] = 1;
	return (r);
}

static	t_matrix	rot_y_matrix(float rot_y)
{
	t_matrix		r;

	rot_y = ((rot_y / 2) * PI) / 180.0;
	r.m[0][0] = cos(rot_y);
	r.m[0][1] = 0;
	r.m[0][2] = -sin(rot_y);
	r.m[0][3] = 0;
	r.m[1][0] = 0;
	r.m[1][1] = 1;
	r.m[1][2] = 0;
	r.m[1][3] = 0;
	r.m[2][0] = sin(rot_y);
	r.m[2][1] = 0;
	r.m[2][2] = cos(rot_y);
	r.m[2][3] = 0;
	r.m[3][0] = 0;
	r.m[3][1] = 0;
	r.m[3][2] = 0;
	r.m[3][3] = 1;
	return (r);
}

static	t_matrix	rot_z_matrix(float rot_z)
{
	t_matrix		r;

	rot_z = ((rot_z / 2) * PI) / 180.0;
	r.m[0][0] = cos(rot_z);
	r.m[0][1] = -sin(rot_z);
	r.m[0][2] = 0;
	r.m[0][3] = 0;
	r.m[1][0] = -sin(rot_z);
	r.m[1][1] = cos(rot_z);
	r.m[1][2] = 0;
	r.m[1][3] = 0;
	r.m[2][0] = 0;
	r.m[2][1] = 0;
	r.m[2][2] = 1;
	r.m[2][3] = 0;
	r.m[3][0] = 0;
	r.m[3][1] = 0;
	r.m[3][2] = 0;
	r.m[3][3] = 1;
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

