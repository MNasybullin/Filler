/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:15:16 by sdiego            #+#    #+#             */
/*   Updated: 2020/09/07 19:33:31 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/visual.h"

void	clear_window(t_sdl *s)
{
	SDL_Rect rect;

	if (SDL_SetRenderDrawColor(s->ren, 0, 0, 0, 1) == -1)
		quit(s, SDL);
	if (SDL_RenderClear(s->ren) == -1)
		quit(s, SDL);
	if (SDL_SetRenderDrawColor(s->ren, 255, 0, 0, 1) == -1)
		quit(s, SDL);
	rect.h = 15;
	rect.w = 525;
	rect.x = 0;
	rect.y = 0;
	SDL_RenderFillRect(s->ren, &rect);
	if (SDL_SetRenderDrawColor(s->ren, 0, 0, 255, 1) == -1)
		quit(s, SDL);
	rect.h = 15;
	rect.w = 525;
	rect.x = 525;
	rect.y = 0;
	SDL_RenderFillRect(s->ren, &rect);
}

void	set_color(t_sdl *s, t_info *f, int i, int j)
{
	if (f->map[i][j] == '.')
	{
		if (SDL_SetRenderDrawColor(s->ren, 128, 128, 128, 1) == -1)
			quit(s, SDL);
	}
	else if (f->map[i][j] == 'O' || f->map[i][j] == 'o')
	{
		s->score_o += 1;
		if (SDL_SetRenderDrawColor(s->ren, 255, 0, 0, 1) == -1)
			quit(s, SDL);
	}
	else if (f->map[i][j] == 'X' || f->map[i][j] == 'x')
	{
		s->score_x += 1;
		if (SDL_SetRenderDrawColor(s->ren, 0, 0, 255, 1) == -1)
			quit(s, SDL);
	}
}

void	draw_score(t_sdl *s)
{
	SDL_Rect rect;

	if (s->score_o > s->score_x)
	{
		if (SDL_SetRenderDrawColor(s->ren, 255, 0, 0, 1) == -1)
			quit(s, SDL);
	}
	else if (s->score_o < s->score_x)
	{
		if (SDL_SetRenderDrawColor(s->ren, 0, 0, 255, 1) == -1)
			quit(s, SDL);
	}
	else
		return ;
	rect.h = 15;
	rect.w = 1050;
	rect.x = 0;
	rect.y = 1035;
	SDL_RenderFillRect(s->ren, &rect);
}

void	draw(t_sdl *s, t_info *f, int x, int i)
{
	int			y;
	int			j;
	SDL_Rect	rect;

	clear_window(s);
	while (i < f->map_size_x)
	{
		j = 0;
		y = 35;
		while (j < f->map_size_y)
		{
			set_color(s, f, i, j);
			rect.h = s->s_x;
			rect.w = s->s_y;
			rect.x = y;
			rect.y = x;
			SDL_RenderFillRect(s->ren, &rect);
			y = y + s->interval + s->s_y;
			j++;
		}
		x = x + s->interval + s->s_x;
		i++;
	}
	draw_score(s);
}

void	map_info(t_info *f, int param, int i)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau") != NULL)
		{
			if (param == 1)
			{
				while (line[i] && (line[i] <= '0' || line[i] >= '9'))
					i++;
				f->map_size_x = ft_getnbr(&line[i]);
				while (line[i] && (line[i] >= '0' && line[i] <= '9'))
					i++;
				f->map_size_y = ft_getnbr(&line[i + 1]);
				f->map = init_array_char(f->map_size_x, f->map_size_y);
			}
			get_map_info(f, 0, 0);
			ft_strdel(&line);
			break ;
		}
		else
			ft_strdel(&line);
	}
}
