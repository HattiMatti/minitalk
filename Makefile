# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 17:05:11 by msiitone          #+#    #+#              #
#    Updated: 2024/05/07 18:37:54 by msiitone         ###   ########.fr        #
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
	$(COMPILE) server.c -o server -L$(LIBFTDIR) -lft

client :
	$(MAKE) -C $(LIBFTDIR)
	$(COMPILE) client.c -o client -L$(LIBFTDIR) -lft

clean :
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -f server
	rm -f client
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all libft clean fclean re
