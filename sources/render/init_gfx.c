/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:08:39 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/26 11:16:40 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <mlx.h>

t_env		init_gfx(float res_x, float res_y, char *win_name)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, res_x, res_y, win_name);
	return (env);
}
