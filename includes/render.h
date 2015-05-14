/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:58:06 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/14 14:18:05 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "camera.h"
# include "matrix.h"

typedef struct s_env	t_env;
typedef struct s_ray	t_ray;
typedef struct s_sphere	t_sphere;
typedef struct s_plane	t_plane;
typedef struct s_cone	t_cone;
typedef union u_shape	t_shape;
typedef union u_color	t_color;
typedef struct s_object	t_object;
typedef struct s_scene	t_scene;

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

union					u_color
{
	unsigned int		val;
	unsigned char		rgb[4];
};

struct					s_object
{
	t_matrix			o2w;
	t_matrix			w2o;
	t_vertex			pos;
	t_color				color;
	float				(*intersect)(t_ray const ray);
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
t_color					new_color(unsigned char r,
									unsigned char g,
									unsigned char b);
int						put_pixel(t_env gfx, int x, int y, int color);
float					intersect_sphere(t_ray const ray);
float					intersect_plane(t_ray const ray);
float					intersect_cylinder(t_ray const ray);
float					intersect_cone(t_ray const ray);
float					solve_quadratic(float a, float b, float c);

#endif
