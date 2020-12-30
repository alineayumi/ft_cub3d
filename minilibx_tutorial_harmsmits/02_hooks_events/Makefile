# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 15:29:14 by afukuhar          #+#    #+#              #
#    Updated: 2020/12/30 01:07:16 by afukuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFILES = *.c
OFILES = *.o

test:
		@$(CC) main.c -g -lz -L../mlx -lmlx -framework OpenGL -framework AppKit -lm

print_kh:
		@$(CC) print_keycode.c -g -lz -L../mlx -lmlx -framework OpenGL -framework AppKit -lm

print_mouse_pressed:
		@$(CC) mouse_pressed.c -g -lz -L../mlx -lmlx -framework OpenGL -framework AppKit -lm

events:
		@$(CC) events.c -g -lz -L../mlx -lmlx -framework OpenGL -framework AppKit -lm

clean:
		@/bin/rm -f $(OFILES)
