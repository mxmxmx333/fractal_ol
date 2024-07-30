# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 16:24:52 by mbonengl          #+#    #+#              #
#    Updated: 2024/07/30 15:48:21 by mbonengl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name 		:= 	fractol
FIVEHUNDRED	:= 	-D MAX_IT=500
ONETHOUSAND	:= 	-D MAX_IT=1000
FIVEK		:= 	-D MAX_IT=5000
TENK		:= 	-D MAX_IT=10000
CFLAGS 		:= 	-O3 -g -I./includes -I./libft/libft.h -Wall -Wextra -Werror
LDFLAGS		:= 	-L./libft -lft -L/usr/local/lib/minilibx.a -lmlx -lXext -lX11 -lm 
CC 			:= 	cc
SRC_DIR 	:= 	./src
OBJ_DIR 	:= 	./obj
LIBFT_DIR	:= 	./libft
LIBFT		:= 	$(LIBFT_DIR)/libft.a
SRC 		:=	$(SRC_DIR)/colorsets.c \
				$(SRC_DIR)/mandelbrot_set.c \
				$(SRC_DIR)/math_scale_and_range.c \
				$(SRC_DIR)/coloring.c \
				$(SRC_DIR)/math_complex.c \
				$(SRC_DIR)/main.c \
				$(SRC_DIR)/buddhabrot.c \
				$(SRC_DIR)/helpers.c \
				$(SRC_DIR)/move.c \
				$(SRC_DIR)/zoom.c \
				$(SRC_DIR)/init.c \
				$(SRC_DIR)/controls.c \
				$(SRC_DIR)/renders.c \
				$(SRC_DIR)/julia_set.c \
				$(SRC_DIR)/colorsets_two.c \
				$(SRC_DIR)/parameters.c  \
				$(SRC_DIR)/ft_atof.c \
				$(SRC_DIR)/soph_coloring.c \
				$(SRC_DIR)/shading_julia.c \
				$(SRC_DIR)/shading_mandelbrot.c \
				$(SRC_DIR)/parameters_conditions.c \
				$(SRC_DIR)/messages.c \
				$(SRC_DIR)/rgb_and_mlx.c \
				$(SRC_DIR)/control_colors.c \
				$(SRC_DIR)/buddhabrot_colors.c \
				$(SRC_DIR)/check_float_int.c
OBJ 		:= 	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(Name)

$(Name): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ) $(LDFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

fast: fclean $(OBJ) $(LIBFT)
	$(CC) $(IMP) $(CFLAGS) -o $(Name) $(OBJ) $(LDFLAGS)

memory: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INFFLAG) -o $(Name) $(OBJ) $(LDFLAGS)

500: CFLAGS += $(FIVEHUNDRED)
500: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ) $(LDFLAGS)

1000: CFLAGS += $(ONETHOUSAND)
1000: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ) $(LDFLAGS)

5000: CFLAGS += $(FIVEK)
5000: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ) $(LDFLAGS)

10000: CFLAGS += $(TENK)
10000: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ) $(LDFLAGS)


clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(Name)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 500 1000 5000 10000