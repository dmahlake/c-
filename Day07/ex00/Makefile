# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 12:15:02 by dmahlake          #+#    #+#              #
#    Updated: 2018/06/14 12:15:06 by dmahlake         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = whatever
FLAGS = -Wall -Wextra -Werror
SRC = whatever.cpp

all: $(NAME)

$(NAME):
	   @clang++ $(SRC) -o $(NAME)

clean:
	@rm $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

