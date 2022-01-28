NAME = push_swap

BONUS_NAME = checker

SRC = ft_atoi.c array_checks.c bubble_sort.c exec_ops.c fill_stack.c main_ops.c main.c ps_sort.c push_swap.c stack.c

OBJ = $(SRC:.c=.o)

BONUS =	 ft_atoi.c array_checks.c bubble_sort.c exec_ops.c fill_stack.c main_ops.c ps_sort.c push_swap.c stack.c checker.c ft_strncmp.c ft_strlen.c get_next_line.c get_next_line_utils.c

BONUS_OBJ = $(BONUS:.c=.o)

HDRS = push_swap_lib.h stack.h

BONUS_HDRS = push_swap_lib.h stack.h  checker.h get_next_line.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(HDRS) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(BONUS_HDRS)
		$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME) 

re:	fclean all

.PHONY: all clean fclean bonus
