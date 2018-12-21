# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloncham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 16:24:52 by lloncham          #+#    #+#              #
#    Updated: 2018/12/20 17:48:59 by lloncham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAG = -Wall -Wextra -Werror 

SRC = algo.c main.c read_file.c valid_file.c

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
