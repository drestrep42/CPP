NAME	=	BraiiiiiiinnnzzzZ

CC		=	g++
CFLAGS	=	-g3 -Wall -Wextra -Werror

SRCS	=	main.cpp	Zombie.cpp	newZombie.cpp	randomChump.cpp

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	
fclean: clean	
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
