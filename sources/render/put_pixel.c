/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:05:10 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/28 14:25:52 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "render.h"

int			put_pixel(t_env gfx, int x, int y, int color)
{
	return (mlx_pixel_put(gfx.mlx, gfx.win, x, y, color));
}
