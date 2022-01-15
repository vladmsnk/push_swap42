SRCS			=	main.c ft_atoi.c ft_strlen.c  stack.c
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