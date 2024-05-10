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

SRCS = server.c client.c

LIBFTDIR = ./libft

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

COMPILE = cc $(CFLAGS)

OBJ = $(SRCS:.c=.o)


all : libft server client

libft :
	$(MAKE) -C $(LIBFTDIR)

server :
	$(COMPILE) server.c -o server -L$(LIBFTDIR) -lft

client :
	$(COMPILE) client.c -o client -L$(LIBFTDIR) -lft


clean :
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -f server
	rm -f client
	$(MAKE) -C $(LIBFTDIR) clean

re: fclean all

.PHONY: all libft clean fclean re
