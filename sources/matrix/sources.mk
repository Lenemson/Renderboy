# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/22 14:53:37 by jibanez           #+#    #+#              #
#    Updated: 2015/03/23 17:27:32 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MATRIX = matrix_product.c \
		 mult_matrix_vector.c \
		 mult_matrix_vertex.c

OBJ += $(MATRIX:.c=.o)

$(OBJDIR)/%.o: $(MATRIXDIR)/%.c
	$(COMPIL)
	$(INFO)
