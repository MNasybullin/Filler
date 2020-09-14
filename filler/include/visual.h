/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:31:32 by sdiego            #+#    #+#             */
/*   Updated: 2020/09/07 19:34:51 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "SDL.h"

# define WIN_W	1050
# define WIN_H	1050

typedef	struct		s_sdl
{
	SDL_Window		*win;
	SDL_Event		e;
	SDL_Renderer	*ren;
	int				run;
	int				space;
	int				right;
	int				interval;
	int				s_x;
	int				s_y;
	int				score_o;
	int				score_x;

}					t_sdl;

void				key_function(t_sdl *s, t_info *f);
void				key_press(t_sdl *m);
void				init(t_sdl *s);
void				quit(t_sdl *s, char *c);
void				clear_window(t_sdl *s);
void				set_color(t_sdl *s, t_info *f, int i, int j);
void				draw_score(t_sdl *s);
void				draw(t_sdl *s, t_info *f, int x, int i);
void				map_info(t_info *f, int param, int i);

#endif
