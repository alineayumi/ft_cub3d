# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 15:29:14 by afukuhar          #+#    #+#              #
#    Updated: 2020/10/31 15:56:48 by afukuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = main.c

CFILES = *.c
OFILES = *.o

test:
		@$(CC) $(SRC) -g -L../mlx -lmlx -framework OpenGL -framework AppKit

clean:
		@/bin/rm -f $(OFILES)
