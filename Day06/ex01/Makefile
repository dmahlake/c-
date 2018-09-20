# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 10:04:07 by dmahlake          #+#    #+#              #
#    Updated: 2018/06/05 12:14:16 by dmahlake         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serial
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp

all: $(NAME)

$(NAME):
	   @clang++ $(SRC) -o $(NAME)

clean:
	@rm $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all
