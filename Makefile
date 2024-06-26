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
CFLAGS 	:=  -lmlx -lXext -lX11 -lm -g
CC 		:= cc
SRC 	:= main.c
OBJ 	:= $(SRC:.c=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re