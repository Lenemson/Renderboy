/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:05:10 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/15 15:04:37 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render.h"

void		put_pixel_b_endian(t_env gfx, int x, int y, t_color color)
{
	int		i;

	i = (gfx.pixel_size * x) + (gfx.line_size * y);
	if (gfx.pixel_size == 4)
		gfx.img_addr[i] = color.rgb[0];
	else
		i--;
	gfx.img_addr[i + 1] = color.rgb[1];
	gfx.img_addr[i + 2] = color.rgb[2];
	gfx.img_addr[i + 3] = color.rgb[3];
}

void		put_pixel_l_endian(t_env gfx, int x, int y, t_color color)
{
	int		i;

	i = (gfx.pixel_size * x) + (gfx.line_size * y);
	gfx.img_addr[i] = color.rgb[3];
	gfx.img_addr[i + 1] = color.rgb[2];
	gfx.img_addr[i + 2] = color.rgb[1];
	if (gfx.pixel_size == 4)
		gfx.img_addr[i + 3] = color.rgb[0];
}

void		put_pixel(t_env gfx, int x, int y, t_color color)
{
	gfx.put_pixel(gfx, x, y, color);
}
