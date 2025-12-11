/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:41:19 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/11 14:10:04 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_intlen(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	display(int *tab, int size, int k)
{
	int i;
	int n;
	int j;
	int x;

	i = 0;
	n =  ft_intlen(k) + 26;
	while (i < n)
	{
		ft_printf("%c", '-');
		i++;
	}
	ft_printf("%c", '\n');
	ft_printf("%s%s%d%s\n", "| ", "Number of exchanges : ", k, " |");
	i = 0;
	while (i < n)
	{
		ft_printf("%c", '-');
		i++;
	}
	ft_printf("%c", '\n');
	j = 0;
	i = 0;
	while (i < size)
	{
		ft_printf("%s", "| ~");
		ft_printf("%d", tab[i]);
		j = ft_intlen(tab[i]);
		j = (n - 2) - j;
		x = 0;
		while (x < j -2)
		{
			ft_printf("%c", '-');
			x++;
		}
		ft_printf("%c\n", '|');
		i++;
	}
	i = 0;
	while (i < n)
	{
		ft_printf("%c", '-');
		i++;
	}
	ft_printf("%c", '\n');
	return (0);
}

int display_tape(int *tab_a, int *tab_b, int size_a, int size_b)
{
	int i = 0;
	__builtin_printf("|-----------------|\n");
	__builtin_printf("| tab_a     tab_b |\n");
	__builtin_printf("|-----------------|\n");
	while (i < size_a)
	{
		__builtin_printf("|% 4d   || % 4d   |\n", tab_a[i], tab_b[i]);
		i++;
	}
	ft_printf("%c\n");
	return (0);
}
