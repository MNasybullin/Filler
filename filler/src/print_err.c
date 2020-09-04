/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:18:57 by sdiego            #+#    #+#             */
/*   Updated: 2020/07/27 16:59:27 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i++], 1);
		}
	}
}

void	ft_putendl(char const *s)
{
	if (s)
	{
		ft_putstr(s);
		write(1, "\n", 1);
	}
}

void	exit_print_err(char *s, int error)
{
	ft_putendl(s);
	del_memory();
	exit(error);
}

void	exit_err(int error)
{
	del_memory();
	exit(error);
}
