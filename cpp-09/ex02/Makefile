NAME	= PmergeMe
SRCS	= main.cpp PmergeMe.cpp
CC		= g++
CFLAGS	= -g -O0 -std=c++98 -Wall -Wextra -Werror
RM		= rm -rf

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re