SOURCES := ft_printf.c ft_puts.c
OBJECTS := $(SOURCES:.c=.o)
FLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean