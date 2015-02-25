# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 12:16:09 by jibanez           #+#    #+#              #
#    Updated: 2015/02/25 10:49:38 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CAMERA = get_new_camera.c \
		 set_fov.c \
		 set_camera_pos.c \
		 set_viewplane_pos.c

OBJ += $(CAMERA:.c=.o)

$(OBJDIR)/%.o: $(CAMDIR)/%.c
	$(COMPIL)
	$(INFO)
