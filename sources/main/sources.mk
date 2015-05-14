# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 12:16:09 by jibanez           #+#    #+#              #
#    Updated: 2015/05/14 12:21:19 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN = main.c \
	   get_objects.c \
	   new_sphere.c \
	   new_plane.c \
	   new_cylinder.c \
	   new_cone.c

OBJ += $(MAIN:.c=.o)

$(OBJDIR)/%.o: $(MAINDIR)/%.c
	$(COMPIL)
	$(INFO)
