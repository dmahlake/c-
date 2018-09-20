# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 13:14:53 by dmahlake          #+#    #+#              #
#    Updated: 2018/06/14 13:14:57 by dmahlake         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter
FLAGS = -Wall -Wextra -Werror
SRC = iter.cpp

all: $(NAME)

$(NAME):
	   @clang++ $(SRC) -o $(NAME)

clean:
	@rm $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all
