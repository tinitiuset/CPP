NAME = ex03

COMPILER =	c++
STANDARD =	-std=c++98
DEBUG =		-g0	# 0, 1, 2, 3 DEBUG INFORMATION LEVELS
FLAGS =		-Wall -Werror -Wextra

SRC_FILES =	main.cpp Character.cpp AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp

all: $(NAME)

$(NAME): $(SRC_FILES)
	@$(COMPILER)  $(FLAGS) $(STANDARD) $(DEBUG) $(SRC_FILES) -o $(NAME)
	@echo "Compiled"

clean:
	@rm -f $(NAME)
	@echo "Cleared executable"

re: clean all

.PHONY: all clean re