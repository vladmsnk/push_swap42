SRCS			=	stack_to_array.c ft_atoi.c ft_itoa.c ft_stack_len.c  stack.c bubble_sort.c push_swap.c main.c fill_with_ind.c
					
OBJS			= $(SRCS:.c=.o)
 
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -I.
 
NAME			= start
 
all:			$(NAME)
 
$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(OBJS)
 
clean:
				$(RM) $(OBJS) *.o
 
fclean:			clean
				$(RM) $(NAME)
 
re:				fclean $(NAME)

 
.PHONY:			all clean fclean re 