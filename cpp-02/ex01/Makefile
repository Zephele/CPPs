NAME = fixed
SRCS = Fixed.cpp main.cpp
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		${RM} *.o

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re