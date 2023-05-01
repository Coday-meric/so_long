
INC=/usr/include
INCLIB=$(INC)/../lib
INCMYLIB=./lib/
INCCORE=./core/

NAME = so_long

SRC = main.c $(INCCORE)bruteforce.c $(INCCORE)map.c $(INCCORE)enemy.c $(INCCORE)display.c $(INCCORE)display_animate.c $(INCCORE)display_scoreboard.c $(INCCORE)hooks.c $(INCCORE)check_move.c $(INCCORE)check_map.c $(INCCORE)check_map2.c $(INCMYLIB)ft_strdup.c $(INCMYLIB)ft_itoa.c $(INCMYLIB)ft_split.c $(INCMYLIB)ft_strlen.c $(INCMYLIB)ft_strlcpy.c $(INCMYLIB)ft_putchar_fd.c $(INCMYLIB)ft_putnbr_fd.c $(INCMYLIB)ft_putstr_fd.c $(INCMYLIB)ft_bzero.c $(INCMYLIB)ft_calloc.c

FLAG = -Wall -Werror -Wextra

LFLAGS = -lbsd -L./minilibx -lmlx -L$(INCLIB) -lXext -lX11 -lm

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):	$(OBJ)
		gcc $(FLAG) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -rf *.o
	rm -rf $(INCMYLIB)*.o
	rm -rf $(INCCORE)*.o

fclean: clean
	rm -rf $(NAME)

re: clean all
