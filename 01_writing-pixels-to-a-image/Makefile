# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 15:29:14 by afukuhar          #+#    #+#              #
#    Updated: 2020/11/01 16:27:20 by afukuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = main.c

CFILES = *.c
OFILES = *.o

test:
		@$(CC) $(CFILES) -g -lz -L../mlx -lmlx -framework OpenGL -framework AppKit -lm

clean:
		@/bin/rm -f $(OFILES)
