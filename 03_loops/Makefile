# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 15:29:14 by afukuhar          #+#    #+#              #
#    Updated: 2020/11/19 14:10:27 by afukuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFILES = aux.c draw_*.c
OFILES = *.o

test:
		@$(CC) main.c $(CFILES) -g -lz -L../mlx -lmlx -framework OpenGL -framework AppKit -lm

clean:
		@/bin/rm -f $(OFILES)
