/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:15:35 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/18 00:07:02 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	HOOKS_H
# define HOOKS_H

#include "../mlx/mlx.h"
#include <stdio.h>

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_5			23
# define KEY_6			22
# define KEY_7			26
# define KEY_8			28
# define KEY_9			25
# define KEY_0			29
# define KEY_MINUS		27
# define KEY_EQUAL		24
# define KEY_DEL		51
# define KEY_TAB		48
# define KEY_CAPS		272
# define KEY_SHIFT_L	257
# define KEY_SHIFT_R	258
# define KEY_FN			279
# define KEY_CTRL		256
# define KEY_OPT		261
# define KEY_CMD		259
# define KEY_SPC		49
# define KEY_TOP		126
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_COMMA		43
# define KEY_DOT		47
# define KEY_SLASH		44
# define KEY_SEMICOLON	41
# define KEY_APOSTROPHE	39
# define KEY_BRAQ_OPEN	33
# define KEY_BRAQ_CLOSE	30
# define KEY_BACKSLASH	42
# define KEY_RETURN		36
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_T			17
# define KEY_Y			16
# define KEY_U			32
# define KEY_I			34
# define KEY_O			31
# define KEY_P			35
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_F			3
# define KEY_G			5
# define KEY_H			4
# define KEY_J			38
# define KEY_K			40
# define KEY_L			37
# define KEY_Z			6
# define KEY_X			7
# define KEY_C			8
# define KEY_V			9
# define KEY_B			11
# define KEY_N			45
# define KEY_M			46

#endif
