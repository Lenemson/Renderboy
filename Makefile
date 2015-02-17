# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 11:59:13 by jibanez           #+#    #+#              #
#    Updated: 2015/02/17 14:50:48 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raytracer

# Directories

SRCDIR = sources
OBJDIR = objects
INCDIR = includes

MAINDIR = $(SRCDIR)/main
CAMDIR = $(SRCDIR)/camera

# Libraries

LIBFT = libft
LIB3D = lib3d

# Format

GREEN = \x1b[32;01m
ORANGE = \x1b[33;01m
STOP_COLOR = \x1b[0m
OK = $(GREEN)--> [OK]$(STOP_COLOR)
INFO = echo "Compile $< to $@ $(OK)"

# Compilation / Linking

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OFLAGS =
IFLAGS = -I$(INCDIR) -I$(LIBFT)/includes -I$(LIB3D)/includes
LFLAGS = -L$(LIBFT) -lft -L$(LIB3D) -l3d -lm
RM = rm -rf

COMPIL = $(CC) $(CFLAGS) $(OFLAGS) $(IFLAGS) -o $@ -c $<
LINK = $(CC) $(LFLAGS) -o $@ $^

# Include sources.mk

include $(MAINDIR)/sources.mk
include $(CAMDIR)/sources.mk

POBJ = $(addprefix $(OBJDIR)/, $(OBJ))


# Rules

.PHONY: all clean re fclean lib3d libft

all: $(OBJDIR) $(LIB3D) $(LIBFT) $(NAME)

$(NAME): $(POBJ)
	$(LINK)
	@echo "$(GREEN)--> [Done!] --> ./$@ $(STOP_COLOR)"

$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "$(ORANGE)Create $(OBJDIR) directory$(STOP_COLOR)"

$(LIBFT):
	make -C $(LIBFT)

$(LIB3D):
	make -C $(LIB3D)

clean:
	@$(RM) $(OBJDIR)
	@echo "$(ORANGE)Remove $(OBJDIR) directory$(STOP_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(GREEN)--> [Clean!]$(STOP_COLOR)"

re: fclean all
