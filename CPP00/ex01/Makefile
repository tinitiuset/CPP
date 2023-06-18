NAME = phonebook

COMPILER =	c++
STANDARD =	-std=c++98
DEBUG =		-g0	# 0, 1, 2, 3 DEBUG INFORMATION LEVELS
FLAGS =		-Wall -Werror -Wextra

SRC_FILES =	main.cpp \
			phonebook.cpp \
			contact.cpp

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(COMPILER)  $(FLAGS) $(STANDARD) $(DEBUG) $(SRC_FILES) -o $(NAME)
	@echo "Compiled"

clean:
	@rm -f $(SRC_OBJS)
	@echo "Cleared .o and .a files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleared executable"

re: clean all

.PHONY: all clean fclean re