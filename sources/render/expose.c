/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 14:18:21 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/15 14:41:30 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "mlx.h"

int		expose(t_scene *scene)
{
	mlx_put_image_to_window(scene->gfx.mlx, scene->gfx.win,
			scene->gfx.img, 0, 0);
	return (0);
}
