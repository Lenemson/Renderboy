/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:29:45 by jibanez           #+#    #+#             */
/*   Updated: 2015/03/21 17:07:52 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_color			new_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color		new;

	new.rgb[0] = b;
	new.rgb[1] = g;
	new.rgb[2] = r;
	new.rgb[3] = 0;
	return (new);
}
