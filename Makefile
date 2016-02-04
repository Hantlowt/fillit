# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhote <alhote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/19 15:42:18 by alhote            #+#    #+#              #
#    Updated: 2016/01/21 15:35:46 by alhote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	fillit.c\
		ft_display.c\
		ft_parser.c\
		ft_readfile.c\
		tetriminos.c\
		collide.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1m\033[36mCompilation libft...\033[0m"
	@make glu -C libft
	@echo "\033[1m\033[36mLancement compilation fillit...\033[0m"
	@clang -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I. -Ilibft -Llibft -lft

%.o: %.c
	@clang -Wall -Wextra -Werror -c -I. -Ilibft $<

glu: $(OBJ)
	@echo "\033[1m\033[36mLancement compilation fillit...\033[0m"
	@clang -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I. -Ilibft -Llibft -lft
	@rm -rf $(OBJ)

clean:
	@echo "LIBFT: LET'S CLEAN IT"
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@echo "LIBFT: LET'S FCLEAN IT"
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all