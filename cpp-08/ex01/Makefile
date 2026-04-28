NAME	= span
SRCS	= Span.cpp main.cpp
CC		= c++
CFLAGS	= -std=c++98 -Wall -Werror -Wextra
RM		= rm -rf

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY:	all clean fclean re
