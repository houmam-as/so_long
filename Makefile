# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 16:16:53 by hait-sal          #+#    #+#              #
#    Updated: 2023/04/21 18:43:56 by hait-sal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_NAME = so_long_bonus

SRC =	game.c \
		game_mlx_part.c \
		game_errors_check.c \
		game_coins_and_invalid_check.c \
		game_main.c \
		game_map_read.c \
		game_mouvements.c \
		game_utils.c \
		game_valid_path.c \
		get_next_line.c \
		get_next_line_utils.c \
		my_printf.c

SRCBONUS =	bonus/my_game_bonus.c \
			bonus/mlx_part_bonus.c \
			bonus/errors_check_bonus.c \
			bonus/coins_and_invalid_check_bonus.c \
			bonus/main_bonus.c \
			bonus/map_read_bonus.c \
			bonus/mouvements_bonus.c \
			bonus/utils_bonus.c \
			bonus/valid_path_bonus.c \
			bonus/gnl_bonus.c \
			bonus/gnl_utils_bonus.c \
			bonus/printf_bonus.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJ) so_long.h
	@echo finishing
	@cc $(OBJ) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)
	
$(BONUS_NAME) : $(OBJBONUS) bonus/so_long_bonus.h
	@echo finishing
	@cc $(OBJBONUS) -lmlx -framework OpenGL -framework AppKit  -o $(BONUS_NAME)

%.o : %.c
	@echo compiling
	@cc $(FLAGS) -c $^ -o $@

clean :
	@echo cleaning *.o
	@rm -f $(NAME) $(OBJ) $(OBJBONUS)

fclean : clean
	@echo removing so_long.a and bonus/so_long_bonus.a and *.o
	@rm -f $(NAME) $(BONUS_NAME) $(OBJ) $(OBJBONUS)

re : fclean all