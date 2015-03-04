/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:58:06 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/04 14:41:32 by jibanez          ###   ########.fr       */
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
typedef union u_shape	t_shape;
typedef struct s_object	t_object;

struct					s_env
{
	void				*mlx;
	void				*win;
};

struct					s_ray
{
	t_vertex			o;
	t_vector			dir;
	float				t;
};

struct					s_sphere
{
	float				radius;
	float				sqr_radius;
};

union					u_shape
{
	t_sphere			sphere;
};

struct					s_object
{
	t_vertex			pos;
	t_shape				shape;
	int					color;
	float				(*intersect)(t_object const object, t_ray const ray);
};

struct					s_scene
{
	t_env				gfx;
	t_camera			camera;
	int					n_objects;
	t_object			object[100];
};

t_env					init_gfx(float res_x, float res_y, char *win_name);
int						render(t_scene *scene);
int						trace(t_object object[100],
								int const n,
								t_ray const ray);
t_ray					new_ray(t_vertex o, t_vector dir);
t_ray					construct_ray(t_camera const camera,
										t_vector const up,
										int const x);
int						put_pixel(t_env gfx, int x, int y, int color);

float					intersect_sphere(t_object const object,
											t_ray const ray);
float					solve_quadratic(float a, float b, float c);

#endif
