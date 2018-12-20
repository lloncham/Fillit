# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloncham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 16:24:52 by lloncham          #+#    #+#              #
#    Updated: 2018/12/20 11:43:25 by lloncham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = algo.c main.c read_file.c valid_file.c

all	: $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror $(SRC) -L./libft -lft
	@echo "Ready!"

clean :
	@rm -f $(NAME)
	@echo "Clean!"

re : clean all
