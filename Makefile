# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibanez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 11:59:13 by jibanez           #+#    #+#              #
#    Updated: 2015/02/03 13:09:10 by jibanez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raytracer

# Directories

SRCDIR = sources
OBJDIR = objects
INCDIR = includes

MAINDIR = $(SRCDIR)/main

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
IFLAGS = -I$(INCDIR) -I$(LIBFT)/includes
LFLAGS = -L$(LIBFT) -lft
RM = rm -rf

COMPIL = $(CC) $(CFLAGS) $(OFLAGS) $(IFLAGS) -o $@ -c $<
LINK = $(CC) $(LFLAGS) -o $@ $^

# Include sources.mk

include $(MAINDIR)/sources.mk

POBJ = $(addprefix $(OBJDIR)/, $(OBJ))


# Rules

.PHONY: all clean re fclean libft

all: $(OBJDIR) $(LIBFT) $(NAME)

$(NAME): $(POBJ)
	$(LINK)
	@echo "$(GREEN)--> [Done!] --> ./$@ $(STOP_COLOR)"

$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "$(ORANGE)Create $(OBJDIR) directory$(STOP_COLOR)"

$(LIBFT):
	make -C $(LIBFT)

clean:
	@$(RM) $(OBJDIR)
	@echo "$(ORANGE)Remove $(OBJDIR) directory$(STOP_COLOR)"

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)
	@echo "$(GREEN)--> [Clean!]$(STOP_COLOR)"

re: fclean all
