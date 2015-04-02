# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/22 14:53:37 by jibanez           #+#    #+#              #
#    Updated: 2015/04/02 11:49:18 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MATRIX = matrix_product.c \
		 mult_matrix_vector.c \
		 mult_matrix_vertex.c \
		 get_trans_matrix.c \
		 get_scale_matrix.c \
		 get_rot_matrix.c

OBJ += $(MATRIX:.c=.o)

$(OBJDIR)/%.o: $(MATRIXDIR)/%.c
	$(COMPIL)
	$(INFO)
