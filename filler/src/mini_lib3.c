/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:41:49 by sdiego            #+#    #+#             */
/*   Updated: 2020/06/08 17:41:49 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2))
			return (0);
		else
			return (1);
	}
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*s1;
	const char	*s2;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		s1 = haystack;
		s2 = needle;
		while (*s1 == *s2 && *s2 != '\0')
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int	a;
	int	b;

	b = n % 10;
	n = n / 10;
	if (b < 0 || n < 0)
	{
		ft_putchar('-');
		n = -n;
		b = -b;
	}
	if (n != 0)
	{
		a = 1;
		while (a * 10 <= n)
			a = a * 10;
		while (a != 0)
		{
			ft_putchar(n / a % 10 + '0');
			a = a / 10;
		}
	}
	ft_putchar(b + '0');
}
