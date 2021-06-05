# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paim <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/16 17:34:35 by paim              #+#    #+#              #
#    Updated: 2016/09/30 18:51:02 by paim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fractol

SRC = main.c\
	  error.c\
	  fractal.c\
	  fractal2.c\
	  init_fract.c\
	  key_event.c\
	  mouse_event.c\
	  manuel.c\
	  piximg.c

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re libft minilibx

all: $(NAME)

$(NAME) : libft minilibx
	@clang $(SRC) -o $(NAME) -L./libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "Easy compil ma poule"

minilibx:
	@make -C minilibx_macos

libft:
	@make -C libft

clean:
	@make -C minilibx_macos/ clean
	@make -C libft/ clean
	@rm -f $(OBJ)
	@echo "T'inquiete pas ca delete juste les .o :)"

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "La tu peux stresser parcque je delete touuuuuuuuuuuut"

re: fclean all
