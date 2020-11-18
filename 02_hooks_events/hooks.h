/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:09:59 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/18 18:57:24 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	HOOKS_H
# define HOOKS_H

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct					s_vars
{
	void						*mlx;
	void						*win;
}								t_vars;

# define KEY_1					18
# define KEY_2					19
# define KEY_3					20
# define KEY_4					21
# define KEY_5					23
# define KEY_6					22
# define KEY_7					26
# define KEY_8					28
# define KEY_9					25
# define KEY_0					29
# define KEY_MINUS				27
# define KEY_EQUAL				24
# define KEY_DEL				51
# define KEY_TAB				48
# define KEY_CAPS				272
# define KEY_SHIFT_L			257
# define KEY_SHIFT_R			258
# define KEY_FN					279
# define KEY_CTRL				256
# define KEY_OPT				261
# define KEY_CMD				259
# define KEY_SPC				49
# define KEY_TOP				126
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				125
# define KEY_COMMA				43
# define KEY_DOT				47
# define KEY_SLASH				44
# define KEY_SEMICOLON			41
# define KEY_APOSTROPHE			39
# define KEY_BRAQ_OPEN			33
# define KEY_BRAQ_CLOSE			30
# define KEY_BACKSLASH			42
# define KEY_RETURN				36
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_T					17
# define KEY_Y					16
# define KEY_U					32
# define KEY_I					34
# define KEY_O					31
# define KEY_P					35
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_F					3
# define KEY_G					5
# define KEY_H					4
# define KEY_J					38
# define KEY_K					40
# define KEY_L					37
# define KEY_Z					6
# define KEY_X					7
# define KEY_C					8
# define KEY_V					9
# define KEY_B					11
# define KEY_N					45
# define KEY_M					46
# define KEY_ESC				53

// X11 EVENTS
# define KeyPress				02
# define KeyRelease				03
# define ButtonPress			04
# define ButtonRelease			05
# define MotionNotify			06
# define EnterNotify			07
# define LeaveNotify			08
# define FocusIn				09
# define FocusOut				10
# define KeymapNotify			11
# define Expose					12
# define GraphicsExpose			13
# define NoExpose				14
# define VisibilityNotify		15
# define CreateNotify			16
# define DestroyNotify			17
# define UnmapNotify			18
# define MapNotify				19
# define MapRequest				20
# define ReparentNotify			21
# define ConfigureNotify		22
# define ConfigureRequest		23
# define GravityNotify			24
# define ResizeRequest			25
# define CirculateNotify		26
# define CirculateRequest		27
# define PropertyNotify			28
# define SelectionClear			29
# define SelectionRequest		30
# define SelectionNotify		31
# define ColormapNotify			32
# define ClientMessage			33
# define MappingNotify			34
# define GenericEvent			35
# define LASTEvent				36

// X11 MASKS
# define MASK_NOEVENT			0L
# define MASK_KEYPRESS			1L<<0
# define MASK_KEYRELEASE		1L<<1
# define MASK_BUTTONPRESS		1L<<2
# define MASK_BUTTONRELEASE 	1L<<3
# define MASK_ENTERWINDOW		1L<<4
# define MASK_LEAVEWINDOW		1L<<5
# define MASK_POINTERMOTION		1L<<6
# define MASK_POINTERMOTIONHINT	1L<<7
# define MASK_BUTTON1MOTION		1L<<8
# define MASK_BUTTON2MOTION		1L<<9
# define MASK_BUTTON3MOTION		1L<<10
# define MASK_BUTTON4MOTION		1L<<11
# define MASK_BUTTON5MOTION		1L<<12
# define MASK_BUTTONMOTION		1L<<13
# define MASK_KEYMAPSTATE		1L<<14
# define MASK_EXPOSURE			1L<<15
# define MASK_VISIBILITYCHANGE	1L<<16
# define MASK_STRUCTURENOTIFY	1L<<17
# define MASK_RESIZEREDIRECT	1L<<18
# define MASK_SUBSTRUCTNOTIFY	1L<<19
# define MASK_SUBSTRUCTREDIRECT	1L<<20
# define MASK_FOCUSCHANGE		1L<<21
# define MASK_PROPERTYCHANGE	1L<<22
# define MASK_COLORMAPCHANGE	1L<<23
# define MASK_OWNERGRABBUTTON	1L<<24

#endif
