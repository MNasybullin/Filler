/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:15:27 by sdiego            #+#    #+#             */
/*   Updated: 2020/08/25 10:10:55 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include "../include/mem_lst.h"
# include "../include/get_next_line.h"

/*
** Error messages
*/
# define ERROR	"Error"
# define MALER	"Malloc error"
# define GNL	"Get next line error"
# define SDL	"SDL error"
# define CLOSE	"Visual close"

# define PLAYER	-1
# define ENEMY	-2

/*
** if player = 1 ("O" || "o")
** if player = 2 ("X" || "x")
*/
typedef struct	s_info
{
	int			player;
	char		player_upper;
	char		player_lower;
	char		enemy_upper;
	char		enemy_lower;

	int			map_size_x;
	int			map_size_y;
	char		**map;

	int			piece_size_x;
	int			piece_size_y;
	char		**piece;
	int			put_x;
	int			put_y;
	int			**heatmap;
	int			heatmaptocheck;
}				t_info;

/*
** Printf error
*/
void			exit_print_err(char *s, int error);
void			exit_err(int error);

char			*ft_strstr(const char *haystack, const char *needle);
void			ft_putnbr(int n);
void			ft_putchar(char c);

/*
** Init functions
*/
t_info			*init_info();
char			**init_array_char(int size_x, int size_y);
int				**init_array_int(int size_x, int size_y);

/*
** Get info functions
*/
void			get_player_info(t_info *f);
void			get_map_size(t_info *f, int param, char *line);
void			get_map_info(t_info *f, int x, int y);
void			get_piece_size(t_info *f, char *line);
void			get_piece(t_info *f);
void			player_info(t_info *f, int player);

/*
** Heatmap functions
*/
void			init_heatmap(t_info *f);
void			heatmap(t_info *f);

/*
** Solve piece
*/
void			solve_piece(t_info *f, int sum, int min_sum);
void			put_piece(t_info *f);

#endif
