# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloncham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 16:24:52 by lloncham          #+#    #+#              #
#    Updated: 2019/01/07 13:11:10 by lloncham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAG = -Wall -Wextra -Werror 

SRC = ./srcs/algo.c ./srcs/main.c ./srcs/read_file.c ./srcs/valid_file.c

all	: $(NAME)

$(NAME) :
	@cd libft ; $(MAKE) -f Makefile
	@$(CC) $(CFLAG) -o $(NAME) $(SRC) -L./libft -lft

clean :
	@cd libft ; $(MAKE) -f Makefile clean 


fclean :
	@rm -f $(NAME)
	@cd libft ; $(MAKE) -f Makefile fclean 

re : fclean all
