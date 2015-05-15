/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:29:45 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/15 14:49:42 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_color			new_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color		new;

	new.rgb[0] = 0;
	new.rgb[1] = r;
	new.rgb[2] = g;
	new.rgb[3] = b;
	return (new);
}
