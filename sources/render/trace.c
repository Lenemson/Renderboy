/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:09:01 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/28 15:14:32 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "render.h"

int			trace(t_ray ray, void *objects[100])
{
	int		i;

	i = 0;
	while (objects[i] != 0)
	{
		if (((t_sphere *) objects[i])->type == 1
				&& intersect_sphere(ray, (t_sphere *) objects[i]))
			return (123456);
		i++;
	}
	return (0);
}
