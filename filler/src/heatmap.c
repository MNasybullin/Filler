/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:42:51 by sdiego            #+#    #+#             */
/*   Updated: 2020/07/27 17:13:01 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		heatmap_put_helper_y(t_info *f, int x, int y, int sym)
{
	int	check;

	check = 0;
	if (f->heatmaptocheck == 1)
		sym = 100 + sym;
	if (f->heatmap[x][y] == 0)
	{
		if (sym < 0)
			f->heatmap[x][y] = -sym;
		else
			f->heatmap[x][y] = sym;
		check++;
	}
	return (check);
}

int		heatmap_put(t_info *f, int x, int y, int sym)
{
	int	check;

	check = 0;
	if (f->heatmap[x][y] == sym - 1 || (f->heatmaptocheck == 1))
	{
		if (x - 1 >= 0)
			check += heatmap_put_helper_y(f, x - 1, y, sym);
		if (x + 1 < f->map_size_x)
			check += heatmap_put_helper_y(f, x + 1, y, sym);
		if (y - 1 >= 0)
			check += heatmap_put_helper_y(f, x, y - 1, sym);
		if (y + 1 < f->map_size_y)
			check += heatmap_put_helper_y(f, x, y + 1, sym);
	}
	return (check);
}

int		heatmap_create(t_info *f, int x, int y, int sym)
{
	int	check;

	check = 0;
	if (sym == 1)
		check += heatmap_put(f, x, y, -1);
	else
		check += heatmap_put(f, x, y, sym);
	return (check);
}

void	heatmap(t_info *f)
{
	int	x;
	int	y;
	int	check;
	int	sym;

	check = 1;
	sym = 1;
	while (check != 0)
	{
		check = 0;
		x = 0;
		while (x < f->map_size_x)
		{
			y = 0;
			while (y < f->map_size_y)
			{
				check += heatmap_create(f, x, y, sym);
				y++;
			}
			x++;
		}
		sym++;
	}
}
