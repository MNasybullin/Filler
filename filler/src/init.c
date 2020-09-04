/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 17:01:52 by sdiego            #+#    #+#             */
/*   Updated: 2020/07/27 17:05:55 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

t_info	*init_info(void)
{
	t_info *f;

	f = (t_info *)mem(sizeof(t_info));
	if (f == NULL)
		exit_print_err(MALER, EXIT_FAILURE);
	f->player = 0;
	f->map_size_x = 0;
	f->map_size_y = 0;
	f->piece_size_x = 0;
	f->piece_size_y = 0;
	f->put_x = 0;
	f->put_y = 0;
	f->map = NULL;
	f->piece = NULL;
	f->heatmaptocheck = 0;
	return (f);
}

char	**init_array_char(int size_x, int size_y)
{
	char	**array;
	int		i;

	array = (char **)mem(size_x * sizeof(char *));
	if (array != NULL)
	{
		i = 0;
		while (i < size_x)
		{
			array[i] = (char *)mem(size_y * sizeof(char));
			if (array[i] == NULL)
				exit_print_err(MALER, EXIT_FAILURE);
			i++;
		}
	}
	else
		exit_print_err(MALER, EXIT_FAILURE);
	return (array);
}

int		**init_array_int(int size_x, int size_y)
{
	int	**array;
	int	i;

	array = (int **)mem(size_x * sizeof(int *));
	if (array != NULL)
	{
		i = 0;
		while (i < size_x)
		{
			array[i] = (int *)mem(size_y * sizeof(int));
			if (array[i] == NULL)
				exit_print_err(MALER, EXIT_FAILURE);
			i++;
		}
	}
	else
		exit_print_err(MALER, EXIT_FAILURE);
	return (array);
}

void	player_info(t_info *f, int player)
{
	f->player = player;
	if (player == 1)
	{
		f->player_lower = 'o';
		f->player_upper = 'O';
		f->enemy_lower = 'x';
		f->enemy_upper = 'X';
	}
	else if (player == 2)
	{
		f->player_lower = 'x';
		f->player_upper = 'X';
		f->enemy_lower = 'o';
		f->enemy_upper = 'O';
	}
}

void	init_heatmap(t_info *f)
{
	int	x;
	int	y;

	x = 0;
	while (x < f->map_size_x)
	{
		y = 0;
		while (y < f->map_size_y)
		{
			if (f->map[x][y] == '.')
				f->heatmap[x][y] = 0;
			else if (f->map[x][y] == f->player_lower
			|| f->map[x][y] == f->player_upper)
				f->heatmap[x][y] = PLAYER;
			else if (f->map[x][y] == f->enemy_lower
			|| f->map[x][y] == f->enemy_upper)
				f->heatmap[x][y] = ENEMY;
			y++;
		}
		x++;
	}
}
