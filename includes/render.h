/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:58:06 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/29 13:30:10 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "camera.h"
# include "matrix.h"
# include "vector.h"

typedef struct s_env	t_env;
typedef struct s_ray	t_ray;
typedef struct s_sphere	t_sphere;
typedef struct s_plane	t_plane;
typedef struct s_cone	t_cone;
typedef union u_shape	t_shape;
typedef union u_color	t_color;
typedef struct s_object	t_object;
typedef struct s_light	t_light;
typedef struct s_scene	t_scene;

struct					s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*img_addr;
	int					pixel_size;
	int					line_size;
	int					endian;
	void				(*put_pixel)(t_env gfx, int x, int y, t_vector color);
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
	int					id;
	t_matrix			o2w;
	t_matrix			w2o;
	t_matrix			no2w;
	t_vertex			pos;
	t_vector			diffuse_color;
	t_vector			color;
	float				(*intersect)(t_ray const ray);
	t_vector			(*get_normal)(t_vertex const p);
};

struct					s_light
{
	t_vertex			pos;
	t_vector			color;
};

struct					s_scene
{
	t_env				gfx;
	t_camera			camera;
	int					n_objects;
	t_object			object[100];
	int					n_lights;
	t_light				light[10];
};

t_env					init_gfx(float res_x, float res_y, char *win_name);
int						render(t_scene *scene);
t_vector				trace(t_scene *scene, t_ray const ray);
t_vector				shade(t_scene *scene, t_object hit, t_ray ray, float t);
t_ray					new_ray(t_vertex o, t_vector dir);
t_ray					construct_ray(t_camera const camera,
										t_vector const up,
										int const x);
t_ray					mult_matrix_ray(t_ray const src, t_matrix const m);
t_vector				new_color(float r, float g, float b);
t_vector				color_add(t_vector a, t_vector b);
t_vector				color_lerp(t_vector a, t_vector b, t_vector c);
int						expose(t_scene *scene);
void					put_pixel(t_env gfx, int x, int y, t_vector color);
void					put_pixel_l_endian(t_env gfx,
											int x, int y, t_vector color);
void					put_pixel_b_endian(t_env gfx,
											int x, int y, t_vector color);
float					intersect_sphere(t_ray const ray);
float					intersect_plane(t_ray const ray);
float					intersect_cylinder(t_ray const ray);
float					intersect_cone(t_ray const ray);
t_vector				sphere_normal(t_vertex const p);
t_vector				plane_normal(t_vertex const p);
t_vector				cylinder_normal(t_vertex const p);
t_vector				cone_normal(t_vertex const p);
float					solve_quadratic(float a, float b, float c);

#endif
