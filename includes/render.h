/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:58:06 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/28 15:14:15 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "camera.h"

struct					s_env
{
	void				*mlx;
	void				*win;
};

struct					s_scene
{
	struct s_env		gfx;
	t_camera			camera;
	int					n_objects;
	void				*objects[100];
};

struct					s_ray
{
	t_vertex			o;
	t_vector			dir;
	float				t;
};

typedef struct s_env	t_env;
typedef struct s_scene	t_scene;
typedef struct s_ray	t_ray;

t_env	init_gfx(float res_x, float res_y, char *win_name);
int		render(t_scene *scene);
int		trace(t_ray ray, void *objects[100]);
t_ray	new_ray(t_vertex o, t_vector dir);
t_ray	construct_ray(t_camera camera, t_vector up, t_vector right);
int		put_pixel(t_env gfx, int x, int y, int color);

#endif
