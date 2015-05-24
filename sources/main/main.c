/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/24 11:06:00 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "mlx.h"
#include <stdlib.h>

static int		keybinds(int keycode, t_scene *scene)
{
	if (keycode == 53)
	{
		mlx_destroy_image(scene->gfx.mlx, scene->gfx.img);
		mlx_destroy_window(scene->gfx.mlx, scene->gfx.win);
		exit(0);
	}
	return (0);
}

int				main(void)
{
	t_scene		scene;

	scene = get_objects(scene);
	scene.camera = get_new_camera(SCR_WIDTH, SCR_HEIGHT, 90);
	scene.gfx = init_gfx(SCR_WIDTH, SCR_HEIGHT, "raytracer");
	render(&scene);
	mlx_put_image_to_window(scene.gfx.mlx, scene.gfx.win,
			scene.gfx.img, 0, 0);
	mlx_key_hook(scene.gfx.win, keybinds, &scene);
	mlx_expose_hook(scene.gfx.win, expose, &scene);
	mlx_loop(scene.gfx.mlx);
	return (0);
}
