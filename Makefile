NAME = pipex
NAME_BONUS = pipex_bonus

LIBFT = libft
LFLAGS = -L libft -lft

SRC = src/main.c src/init.c src/ft_free.c src/commands.c src/ft_split_pipex.c src/ft_utils.c

SRC_BONUS = src/main.c src/init_bonus.c src/ft_free.c src/commands.c src/ft_split_pipex.c src/ft_utils.c

ifdef BONUS
	SRC = $(SRC_BONUS)
	NAME = $(NAME_BONUS)
endif

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = clang
all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

bonus :
	@make BONUS=1

%.o : %.c
	$(CC) $(FLAGS) -I/src/ -c $< -o $@

clean :
	make -C $(LIBFT) clean
	rm -rf $(OBJ) $(OBJBONUS)

fclean : clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

reb : fclean bonus
