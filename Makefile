# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 16:24:52 by mbonengl          #+#    #+#              #
#    Updated: 2024/06/25 16:36:17 by mbonengl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name 	:= fract_ol
CFLAGS 	:= -g -I./includes
LDFLAGS	:= -L/usr/local/lib/minilibx.a -lmlx -lXext -lX11 -lm 
CC 		:= cc
SRC 	:=	./src/colorsets.c \
			./src/calculate_fractal.c \
			./src/math_scale_and_range.c \
			./src/coloring.c \
			./src/math_complex.c \
			./src/main.c
OBJ 	:= $(SRC:.c=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re