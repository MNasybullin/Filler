# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 14:18:47 by sdiego            #+#    #+#              #
#    Updated: 2020/07/27 17:16:38 by sdiego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sdiego.filler

NAME2 = visualizer

SRC = ./src/get_next_line.c ./src/mem_lst.c ./src/mini_lib.c ./src/mini_lib2.c ./src/mini_lib3.c ./src/print_err.c ./src/init.c ./src/get_info.c ./src/heatmap.c ./src/piece.c

SRC_V = ./src/visualizer.c ./src/visual_draw.c

SRC_F = ./src/filler.c

OBJ = $(SRC:.c=.o)

OBJ_V = $(SRC_V:.c=.o)

OBJ_F = $(SRC_F:.c=.o)

CFLAGS = -o

SDL_FLAGS = -Iinclude -I SDL_lib/SDL2.framework/Headers

SDL2 = -framework SDL2 -F ./SDL_lib/

SDL2_LOAD = -rpath @loader_path/SDL_lib/

INCLUDES = ./include

HEADERS = $(INCLUDES)/filler.h $(INCLUDES)/get_next_line.h $(INCLUDES)/mem_lst.h

HEADERS_V = $(INCLUDES)/visual.h

.PHONY: all clean fclean re

all: $(NAME) $(NAME2)

$(NAME): $(OBJ) $(OBJ_F) $(HEADERS)
	gcc $(CFLAGS) $(NAME) $(OBJ) $(OBJ_F) -I$(INCLUDES)

$(NAME2): $(OBJ) $(OBJ_V) $(HEADERS) $(HEADERS_V)
	gcc $(SRC_V) $(SRC) $(SDL_FLAGS) $(SDL2_LOAD) $(SDL2) $(CFLAGS) $(NAME2)

.c.o: $(HEADERS) $(HEADERS_V)
	gcc -g $(CFLAGS) $(SDL_FLAGS) -c $< -o $@
	
clean:
	rm -fr ./src/*.o 
fclean: clean
	rm -fr $(NAME)
	rm -fr $(NAME2)

re: fclean all
