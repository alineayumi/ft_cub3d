# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 15:29:14 by afukuhar          #+#    #+#              #
#    Updated: 2021/01/10 12:44:39 by afukuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = -L./mlx -lmlx -L./ft_lib -lft

CFILES = *.c

all:
	@echo creating cub3d ...
	@$(MAKE) -C ft_lib re
	@$(MAKE) -C ft_lib clean
	@$(CC) $(CFILES) -g -lz $(LIBS) -framework OpenGL -framework AppKit -lm -o cub3D

clean:
		@/bin/rm -f cub3D
