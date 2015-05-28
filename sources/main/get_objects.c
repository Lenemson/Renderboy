/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:14:32 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/28 15:06:19 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "render.h"
#include "raytracer.h"

static t_scene	get_light(t_scene scene, char **object)
{
	t_light		light;

	light.pos = new_vector(
			ft_atoi(object[1]), ft_atoi(object[2]), ft_atoi(object[3]));
	light.color = new_color(
			ft_atoi(object[4]), ft_atoi(object[5]), ft_atoi(object[6]));
	scene.light[scene.n_lights] = light;
	scene.n_lights++;
	return (scene);
}
/*
static t_camera	get_camera(char	**object)
{
	t_camera	camera;

	camera.pos = new_vector(
			ft_atoi(object[1]), ft_atoi(object[2]), ft_atoi(object[3]));
	camera.pos = new_vector(
			ft_atoi(object[1]), ft_atoi(object[2]), ft_atoi(object[3]));
}
*/
static t_scene	get_shapes(t_scene scene, char **object, int id)
{
	if (ft_strequ(object[0], "sphere"))
	{
		scene.object[scene.n_objects] = get_sphere(object, id);
		scene.n_objects++;
	}
	else if (ft_strequ(object[0], "plane"))
	{
		scene.object[scene.n_objects] = get_plane(object, id);
		scene.n_objects++;
	}
	else if (ft_strequ(object[0], "cylinder"))
	{
		scene.object[scene.n_objects] = get_cylinder(object, id);
		scene.n_objects++;
	}
	else if (ft_strequ(object[0], "cone"))
	{
		scene.object[scene.n_objects] = get_cone(object, id);
		scene.n_objects++;
	}
	return (scene);
}

t_scene			get_objects(t_scene scene, char *scene_file)
{
	char		*line;
	int			fd;
	char		**object;
	int			id;

	fd = open(scene_file, O_RDONLY);
	id = 0;
	scene.n_objects = 0;
	scene.n_lights = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		object = ft_strsplit(line, ' ');
		if (ft_strequ(object[0], "light"))
			scene = get_light(scene, object);
		//else if (ft_strequ(object[0], "camera"))
		//	get_camera();
		else
			scene = get_shapes(scene, object, id);
		free_tab(object);
		ft_strdel(&line);
		id++;
	}
	close(fd);
	ft_putnbr(scene.object[0].color.x);
	return (scene);
}



