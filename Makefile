SRCS			=	 ft_atoi.c stack.c bubble_sort.c push_swap.c main.c fill_with_ind.c exec_ops.c small_sort.c array_checks.c main_ops.c
					
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