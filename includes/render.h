/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:58:06 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/26 12:26:35 by jibanez          ###   ########.fr       */
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

typedef struct s_env	t_env;

t_env	init_gfx(float res_x, float res_y, char *win_name);
int		render(t_env gfx, int x, int y);

#endif
