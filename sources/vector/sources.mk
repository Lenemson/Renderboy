# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 14:04:59 by jibanez           #+#    #+#              #
#    Updated: 2015/02/25 09:28:48 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VECTOR = vector_sum.c \
		 vector_diff.c \
		 mult_vector.c \
		 div_vector.c \
		 magnitude.c \
		 squared_magnitude.c \
		 normalize.c \
		 dot_product.c \
		 cross_product.c \
		 new_vector.c

OBJ += $(VECTOR:.c=.o)

$(OBJDIR)/%.o: $(VECTORDIR)/%.c
	$(COMPIL)
	$(INFO)
