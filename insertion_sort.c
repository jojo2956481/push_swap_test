/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:28:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/05 16:20:11 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

/*
int	insertion_sort(int *tab_a, int size)
{
	int	i;
	int	index;
	int	count;

	count = 0;
	index = 1;
	while (index < size)
	{
		i = 0;
		while (i < index)
		{
			count += ra (tab_a, size);
			i++;
		}
		while (i > 0 && tab_a[0] > tab_a[1])
		{
			count += sa(tab_a, size);
			count += rra(tab_a, size);
			i--;
		}
		while (i > 0)
		{
			count += rra(tab_a, size);
			i--;
		}
		index++;
	}
	count += ra(tab_a, size);
	return (count);
}
*/

// optimisable
int sort_tri(int *tab_a, int size_a)
{
	int count;

	count = 0;

	while (tab_a[0] > tab_a[1] || tab_a[1] > tab_a[2] || tab_a[0] > tab_a[2])
	{
		if (tab_a[0] > tab_a[1])
			count += sa(tab_a, size_a);
		if (tab_a[1] > tab_a[2])
		{
			count += ra(tab_a, size_a);
			count += sa(tab_a, size_a);
			count += rra(tab_a, size_a);
		}
	}
	return (count);
}

int	insertion_sort(int *tab_a, int size)
{
	int	i;
	int	count;
	int	size_a;
	int size_b;
	int	*tab_b;

	tab_b = ft_calloc(size_a, sizeof(int));
	size_a = size;
	size_b = 0;
	count = 0;
	while (size_a > 3)
	{
		count += pb(tab_a, tab_b, &size_a, &size_b);
	}
	count += sort_tri(tab_a, size_a);
	i = 0;
	while (size_b > 0)
	{
		while (tab_b[0] > tab_a[0])
		{
			count += ra(tab_a, size_a);
			i++;
		}
		count += pa(tab_a, tab_b, &size_a, &size_b);
	}
	while (i > 0)
	{
		count += rra(tab_a, size_a);
		i--;
	}
	// if ((size - i) <= (size / 2))
	// {
	// 	while (i > 0)
	// 	{
	// 		count += rra(tab_a, size_a);
	// 		i--;
	// 	}
	// }
	// if ((size - i) > (size / 2))
	// {
	// 	while (i > 0)
	// 	{
	// 		count += ra(tab_a, size_a);
	// 		i--;
	// 	}
	// }
	return (count);
}
