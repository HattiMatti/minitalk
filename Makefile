# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 17:05:11 by msiitone          #+#    #+#              #
#    Updated: 2024/05/16 15:48:16 by msiitone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client libft

SRCS = server.c client.c

LIBFTDIR = ./libft

CFLAGS = -Wall -Wextra -Werror

COMPILE = cc $(CFLAGS)

OBJ = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)

server :
	$(MAKE) -C $(LIBFTDIR)
	$(COMPILE) server.o -o server -L$(LIBFTDIR) -lft

client :
	$(MAKE) -C $(LIBFTDIR)
	$(COMPILE) client.o -o client -L$(LIBFTDIR) -lft

clean :
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -f server
	rm -f client
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all libft clean fclean re
