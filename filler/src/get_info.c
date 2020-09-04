/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 17:01:37 by sdiego            #+#    #+#             */
/*   Updated: 2020/07/27 17:28:26 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	get_player_info(t_info *f)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
	{
		ft_strdel(&line);
		exit_print_err(GNL, EXIT_FAILURE);
	}
	if (ft_strstr(line, "$$$ exec"))
	{
		if (ft_strstr(line, "p1"))
			player_info(f, 1);
		else if (ft_strstr(line, "p2"))
			player_info(f, 2);
	}
	else
	{
		ft_strdel(&line);
		exit_print_err(ERROR, EXIT_FAILURE);
	}
	ft_strdel(&line);
}

void	get_map_size(t_info *f, int param, char *line)
{
	int		i;

	i = 0;
	if (ft_strstr(line, "Plateau"))
	{
		while (line[i] && (line[i] <= '0' || line[i] >= '9'))
			i++;
		f->map_size_x = ft_getnbr(&line[i]);
		while (line[i] && (line[i] >= '0' && line[i] <= '9'))
			i++;
		i++;
		f->map_size_y = ft_getnbr(&line[i]);
	}
	else
	{
		ft_strdel(&line);
		exit_print_err(ERROR, EXIT_FAILURE);
	}
	if (param == 0)
	{
		f->map = init_array_char(f->map_size_x, f->map_size_y);
		f->heatmap = init_array_int(f->map_size_x, f->map_size_y);
	}
	ft_strdel(&line);
	get_map_info(f, 0, 0);
}

void	get_map_info(t_info *f, int x, int y)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
	{
		ft_strdel(&line);
		exit_print_err(GNL, EXIT_FAILURE);
	}
	ft_strdel(&line);
	while (x < f->map_size_x)
	{
		y = 0;
		if (get_next_line(0, &line) != 1)
		{
			ft_strdel(&line);
			exit_print_err(GNL, EXIT_FAILURE);
		}
		while (y < f->map_size_y)
		{
			f->map[x][y] = line[4 + y];
			y++;
		}
		ft_strdel(&line);
		x++;
	}
}

void	get_piece_size(t_info *f, char *line)
{
	int		i;

	i = 0;
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		i++;
	f->piece_size_x = ft_getnbr(&line[i]);
	while (line[i] && (line[i] >= '0' && line[i] <= '9'))
		i++;
	i++;
	f->piece_size_y = ft_getnbr(&line[i]);
	f->piece = init_array_char(f->piece_size_x, f->piece_size_y);
	ft_strdel(&line);
}

void	get_piece(t_info *f)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	while (x < f->piece_size_x)
	{
		y = 0;
		if (get_next_line(0, &line) <= 0)
		{
			ft_strdel(&line);
			exit_print_err(GNL, EXIT_FAILURE);
		}
		while (y < f->piece_size_y)
		{
			f->piece[x][y] = line[y];
			y++;
		}
		x++;
		ft_strdel(&line);
	}
}
