/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/21 16:37:32 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "raytracer.h"

int				keybinds(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int				main(void)
{
	t_scene		scene;

	scene = get_objects(scene);
	scene.camera = get_new_camera(SCR_WIDTH, SCR_HEIGHT, 60);
	scene.gfx = init_gfx(SCR_WIDTH, SCR_HEIGHT, "raytracer");
	mlx_key_hook(scene.gfx.win, keybinds, &scene);
	mlx_expose_hook(scene.gfx.win, render, &scene);
	mlx_loop(scene.gfx.mlx);
	return (0);
}
