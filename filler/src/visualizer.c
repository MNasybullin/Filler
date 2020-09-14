/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:39:47 by sdiego            #+#    #+#             */
/*   Updated: 2020/09/07 19:34:14 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/visual.h"

void	quit(t_sdl *s, char *c)
{
	SDL_DestroyWindow(s->win);
	SDL_DestroyRenderer(s->ren);
	SDL_Quit();
	exit_print_err(c, EXIT_FAILURE);
}

void	init(t_sdl *s)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		quit(s, SDL);
	s->win = SDL_CreateWindow("FILLER", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
	if (s->win == NULL)
		quit(s, SDL);
	s->ren = SDL_CreateRenderer(s->win, -1, SDL_RENDERER_SOFTWARE);
	if (s->ren == NULL)
		quit(s, SDL);
	s->right = 0;
	s->space = 1;
	s->run = 0;
	s->interval = 2;
	s->score_o = 0;
	s->score_x = 0;
}

void	key_press(t_sdl *m)
{
	if (m->e.key.keysym.sym == SDLK_ESCAPE)
		m->run = 1;
	else if (m->e.key.keysym.sym == SDLK_SPACE)
	{
		if (m->space == 0)
			m->space = 1;
		else
			m->space = 0;
	}
	else if (m->e.key.keysym.sym == SDLK_RIGHT)
		m->right = 1;
}

void	key_function(t_sdl *s, t_info *f)
{
	if (s->space == 0)
	{
		map_info(f, 0, 0);
		draw(s, f, 25, 0);
		SDL_RenderPresent(s->ren);
	}
	else if (s->right == 1)
	{
		map_info(f, 0, 0);
		draw(s, f, 25, 0);
		s->right = 0;
		SDL_RenderPresent(s->ren);
	}
}

int		main(void)
{
	t_sdl	s;
	t_info	*f;

	init(&s);
	f = init_info();
	map_info(f, 1, 0);
	s.s_x = (1000 - (f->map_size_x - 1) * s.interval) / f->map_size_x;
	s.s_y = (1000 - (f->map_size_y - 1) * s.interval) / f->map_size_y;
	draw(&s, f, 25, 0);
	SDL_RenderPresent(s.ren);
	while (s.run == 0)
	{
		while (SDL_PollEvent(&s.e) != 0)
		{
			if (s.e.type == SDL_QUIT)
				s.run = 1;
			if (s.e.type == SDL_KEYDOWN)
				key_press(&s);
		}
		s.score_o = 0;
		s.score_x = 0;
		if (s.space == 0 || s.right == 1)
			key_function(&s, f);
	}
	quit(&s, CLOSE);
}
