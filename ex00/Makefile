# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 16:08:49 by drestrep          #+#    #+#              #
#    Updated: 2025/04/10 16:34:17 by drestrep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CC		=	g++
CFLAGS	=	-g3 -Wall -Wextra -Werror

SRCS	=	megaphone.cpp

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
