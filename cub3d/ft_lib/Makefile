# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 21:54:32 by afukuhar          #+#    #+#              #
#    Updated: 2021/01/10 11:39:10 by afukuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

CFILES = ft_libft/*.c ft_get_next_line/*.c ft_printf/*.c
OFILES = *.o
INCLUDES = ./

all:		$(NAME)
	@echo Compiling $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $(CFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

bonus: re

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean