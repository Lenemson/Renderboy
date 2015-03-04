/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:58:06 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/04 13:02:21 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "camera.h"

typedef struct s_env	t_env;
typedef struct s_scene	t_scene;
typedef struct s_ray	t_ray;
typedef struct s_sphere	t_sphere;
typedef struct s_result	t_result;

struct					s_env
{
	void				*mlx;
	void				*win;
};

struct					s_scene
{
	t_env				gfx;
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

struct					s_result
{
	int					n;
	float				t0;
	float				t1;
};

struct					s_sphere
{
	int					type;
	t_vertex			center;
	float				radius;
	float				sqr_radius;
};

t_env					init_gfx(float res_x, float res_y, char *win_name);
int						render(t_scene *scene);
int						trace(t_ray ray, void *objects[100]);
t_ray					new_ray(t_vertex o, t_vector dir);
t_ray					construct_ray(t_camera const camera,
										t_vector const up,
										int const x);
int						put_pixel(t_env gfx, int x, int y, int color);

int						intersect_sphere(t_ray ray, t_sphere *sphere);
t_result				solve_quadratic(float a, float b, float c);

#endif
