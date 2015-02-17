/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/17 16:47:52 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"


int			main(void)
{
	t_camera	camera;
	t_vertex	viewplane_pos;

	camera = get_new_camera(800, 600);
	camera = set_fov(camera, 60);
	viewplane_pos = get_viewplane_pos(camera);
	ft_putnbr(viewplane_pos.x);ft_putchar('\n');////
	ft_putnbr(viewplane_pos.y);ft_putchar('\n');////
	ft_putnbr(viewplane_pos.z);ft_putchar('\n');////
	return (0);
}
