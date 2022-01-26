SRCS			=	 ft_atoi.c ft_itoa.c ft_stack_len.c  stack.c bubble_sort.c push_swap.c main.c fill_with_ind.c exec_ops.c test_ops.c small_sort.c array_funcs.c array_checks.c
					
OBJS			= $(SRCS:.c=.o)
 
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -I.
 
NAME			= push_swap
 
all:			$(NAME)
 
$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(OBJS)
 
clean:
				$(RM) $(OBJS) *.o
 
fclean:			clean
				$(RM) $(NAME)
 
re:				fclean $(NAME)

 
.PHONY:			all clean fclean re 