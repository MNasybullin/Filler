/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:19:47 by sdiego            #+#    #+#             */
/*   Updated: 2020/08/25 10:25:41 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	set_zero_struct(t_info *f)
{
	f->put_x = 0;
	f->put_y = 0;
	f->piece_size_x = 0;
	f->piece_size_y = 0;
	f->heatmaptocheck = 0;
}

void	solve_functions(t_info *f, char *line)
{
	get_piece_size(f, line);
	get_piece(f);
	init_heatmap(f);
	heatmap(f);
	f->heatmaptocheck = 1;
	heatmap(f);
	solve_piece(f, 0, 2147483647);
	put_piece(f);
}

int		main(void)
{
	t_info	*f;
	int		i;
	char	*line;

	i = 0;
	f = init_info();
	get_player_info(f);
	while (get_next_line(0, &line) > 0)
	{
		set_zero_struct(f);
		if (line && ft_strstr(line, "Plateau"))
		{
			get_map_size(f, i, line);
			i++;
		}
		else if (line && ft_strstr(line, "Piece"))
			solve_functions(f, line);
		else
			ft_strdel(&line);
	}
	exit_err(EXIT_SUCCESS);
	return (0);
}
