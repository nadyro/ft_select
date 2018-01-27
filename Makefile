# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 15:34:29 by nsehnoun          #+#    #+#              #
#    Updated: 2018/01/25 17:45:11 by nsehnoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  term_infos.c \
	  aff_select.c \
	  read_select.c \
	  movement.c \
	  select.c \
	  signal_management.c \

NAME = ft_select

LIB = -Llibft -lft

HEADERS = ft_select.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I $(HEADERS) -lncurses

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
