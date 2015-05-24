# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 12:16:09 by jibanez           #+#    #+#              #
#    Updated: 2015/05/24 15:02:56 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RENDER = init_gfx.c \
		 render.c \
		 ray.c \
		 trace.c \
		 color.c \
		 put_pixel.c \
		 solve_quadratic.c \
		 sphere.c \
		 plane.c \
		 cylinder.c \
		 cone.c \
		 expose.c \
		 shade.c

OBJ += $(RENDER:.c=.o)

$(OBJDIR)/%.o: $(RENDERDIR)/%.c
	$(COMPIL)
	$(INFO)
