/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:19:32 by sdiego            #+#    #+#             */
/*   Updated: 2020/07/27 17:21:08 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		check_piece(t_info *f, int x, int y, int *sum)
{
	int	i;
	int	j;
	int	overlay;

	i = 0;
	overlay = 0;
	while (i < f->piece_size_x)
	{
		j = -1;
		while (++j < f->piece_size_y)
		{
			if (f->piece[i][j] == '*')
			{
				if (x + i < 0 || x + i >= f->map_size_x || y + j < 0
				|| y + j >= f->map_size_y || f->heatmap[x + i][y + j] == ENEMY)
					return (0);
				if (f->heatmap[x + i][y + j] == PLAYER)
					overlay++;
				else
					*sum = *sum + f->heatmap[x + i][y + j];
			}
		}
		i++;
	}
	return (overlay == 1 ? 1 : 0);
}

void	solve_piece(t_info *f, int sum, int min_sum)
{
	int	x;
	int	y;

	x = -(f->piece_size_x);
	while (x < f->map_size_x + f->piece_size_x)
	{
		y = -(f->piece_size_y);
		while (y < f->map_size_y + f->piece_size_y)
		{
			sum = 0;
			if (check_piece(f, x, y, &sum) == 1)
			{
				if (sum < min_sum && sum != 0)
				{
					f->put_x = x;
					f->put_y = y;
					min_sum = sum;
				}
			}
			y++;
		}
		x++;
	}
}

void	put_piece(t_info *f)
{
	ft_putnbr(f->put_x);
	ft_putchar(' ');
	ft_putnbr(f->put_y);
	ft_putchar('\n');
}
