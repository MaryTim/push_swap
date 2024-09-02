MY_SOURCES = push_swap.c \
			error_handling.c \
			validation_and_init/input_validation.c \
			validation_and_init/helpers.c \
			validation_and_init/validation_helpers.c \
			validation_and_init/initialization.c \
			operations/operation_helpers.c \
			operations/push.c \
			operations/reverse_rotate.c \
			operations/rotate.c \
			operations/swap.c \
			sorting/tiny_sort.c \
			sorting/sorting_helpers.c \
			sorting/sort.c \
			sorting/targets.c \
			sorting/utils.c \
			sorting/stack_info.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

NAME = push_swap

CC = cc

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	make -C libftPrintfGnl
	$(CC) $(CFLAGS) $(MY_OBJECTS) libftPrintfGnl/libft.a -o $(NAME)

clean:
	make clean -C libftPrintfGnl
	rm -f $(MY_OBJECTS)

fclean: clean
	make fclean -C libftPrintfGnl
	rm -f $(NAME)

re: fclean all