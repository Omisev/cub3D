# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 17:22:35 by raveriss          #+#    #+#              #
#    Updated: 2024/03/01 00:18:25 by raveriss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs
BONUS_SRC_DIR = ./srcs_bonus

# Sources pour la partie obligatoire
SRCS = $(addprefix srcs/, main.c draw/dda_utils.c draw/dda.c draw/game.c \
						draw/minimap.c draw/player.c \
						draw/skyground.c draw/wall.c free/free.c free/garcol.c \
						get/check_images_exist.c get/elem.c get/elem2.c \
						get/input.c get/map.c get/player.c key/key1.c \
						key/key2.c mlx/mlx.c parse/parse.c utils/utils.c \
						utils/utils2.c)

# Sources pour la partie bonus
BONUS_SRCS = $(addprefix srcs_bonus/, main.c draw/dda_utils.c draw/dda.c \
					draw/game.c draw/game_init.c draw/fix_fisheye.c \
					draw/load_texture.c draw/minimap.c draw/player.c \
					draw/ray_utils.c draw/skyground.c draw/wall.c \
					free/free.c free/garcol.c get/check_images_exist.c \
					get/elem.c get/elem2.c get/input.c get/map.c get/player.c \
					key/key1.c key/key2.c key/mouse_event.c mlx/mlx.c \
					parse/parse.c utils/utils.c utils/utils2.c)

						

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -g3 -Wall -Wextra -Werror

# Ajout pour activer Leak Sanitizer conditionnellement
ifneq ($(SANITIZE),)
CFLAGS += -fsanitize=leak
endif

NAME = cub3D

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./minilibx-linux
	cd Lib && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) Lib/lib42.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx-linux/ -I ./Lib/ -lm

bonus : $(BONUS_OBJ)
	make -C ./minilibx-linux
	cd Lib && make
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ) Lib/lib42.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx-linux/ -I ./Lib/ -lm

clean :
	cd minilibx-linux && make clean
	cd Lib && make clean
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

