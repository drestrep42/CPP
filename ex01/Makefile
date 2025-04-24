# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 16:37:24 by drestrep          #+#    #+#              #
#    Updated: 2025/04/24 18:35:41 by drestrep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CC		=	g++
CFLAGS	=	-g -g3 -Wall -Wextra -Werror

SRCS	=	main.cpp	add.cpp		search.cpp

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
