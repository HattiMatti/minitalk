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

NAME = server client

SRCS = server.c client.c

LIBFTDIR = ./libft

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

COMPILE = cc $(CFLAGS)

OBJ = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(COMPILE) server.c -o server -L$(LIBFTDIR) -lft
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
