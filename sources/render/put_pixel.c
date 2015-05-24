/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:05:10 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/24 09:04:19 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render.h"

void		put_pixel_b_endian(t_env gfx, int x, int y, t_vector color)
{
	int		i;

	i = (gfx.pixel_size * x) + (gfx.line_size * y);
	if (gfx.pixel_size == 4)
		gfx.img_addr[i] = 0;
	else
		i--;
	gfx.img_addr[i + 1] = (char)(color.x * 255);
	gfx.img_addr[i + 2] = (char)(color.y * 255);
	gfx.img_addr[i + 3] = (char)(color.z * 255);
}

void		put_pixel_l_endian(t_env gfx, int x, int y, t_vector color)
{
	int		i;

	i = (gfx.pixel_size * x) + (gfx.line_size * y);
	gfx.img_addr[i] = (char)(color.z * 255);
	gfx.img_addr[i + 1] = (char)(color.y * 255);
	gfx.img_addr[i + 2] = (char)(color.x * 255);
	if (gfx.pixel_size == 4)
		gfx.img_addr[i + 3] = 0;
}

void		put_pixel(t_env gfx, int x, int y, t_vector color)
{
	gfx.put_pixel(gfx, x, y, color);
}
