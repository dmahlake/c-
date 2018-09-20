NAME     = ft_retro

GPP      = clang++

FLAGS    = -Wall -Wextra -Werror -Wno-unused

SRC     = main.cpp Game.cpp GameObject.cpp GameObjectField.cpp Rect.cpp Player.cpp ObjectPos.cpp ObjectPos2.cpp

INCLUDE		= -I.
LIB		= -lncurses

all: $(NAME)

$(NAME): $(SRC)
	@$(GPP) $(FLAGS) $(LIB) $(INCLUDE) $^ -o $@
	@echo "\033[32m$(NAME) compiled\033[0m"

clean:
	@rm -f $(NAME)
	@echo "\033[31;1mremoved $(NAME)\033[0m"

fclean: clean

re: fclean all
