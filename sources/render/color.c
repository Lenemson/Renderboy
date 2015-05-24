/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:29:45 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/24 15:03:38 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_vector		new_color(float r, float g, float b)
{
	t_vector	new;

	new.x = r / 255;
	new.y = g / 255;
	new.z = b / 255;
	return (new);
}

t_vector		color_add(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x + b.x;
	new.x = a.y + b.y;
	new.x = a.z + b.z;
	return (new);
}

t_vector		color_lerp(t_vector a, t_vector b, t_vector c)
{
	t_vector	color;

	color.x = (b.x - a.x) * c.x + a.x;
	color.y = (b.y - a.y) * c.y + a.y;
	color.z = (b.z - a.z) * c.z + a.z;
	return (color);
}
