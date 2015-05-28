/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/28 13:52:17 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "mlx.h"
#include "libft.h"
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

static int		usage()
{
	ft_putendl("usage: ./raytracer scene_file");
	return (1);
}

int				main(int ac, char **av)
{
	t_scene		scene;

	if (ac < 2)
		return (usage());
	scene = get_objects(scene, av[1]);
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
