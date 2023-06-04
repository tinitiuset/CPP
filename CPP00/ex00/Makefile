NAME = megaphone

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRC =	megaphone.cpp

SRC_OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) -o $(NAME)
	@echo "Compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SRC_OBJS)
	@echo "Cleared .o and .a files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleared executable"

re: clean all

.PHONY: all clean fclean re