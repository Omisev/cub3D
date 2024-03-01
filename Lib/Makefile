NAME = lib42.a
LIB = $(addprefix Src/ft_, strncmp.c is_alpha.c strstr.c split.c atoi.c)
FT_PRINTF = $(addprefix Src/ft_, len_nb_hexa.c len_nb.c memset.c pointeur.c printf.c putchar.c\
putnbr_base_hex.c putnbr_base_neg.c putnbr_base.c putstr.c)
GNL = $(addprefix Src/get_next_, line.c line_utils.c)
OBJS_FT = ${FT_PRINTF:.c=.o}
OBJ_GNL = ${GNL:.c=.o}
OBJ_LIB = ${LIB:.c=.o}
OBJ = $(OBJ_GNL) $(OBJS_FT) $(OBJ_LIB)
CC = cc
FLAGS = -Wall -Werror -Wextra

all: $(NAME) clean

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re