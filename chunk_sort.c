/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:59:41 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/14 11:26:20 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"

static void    ft_swap(int *a, int *b)
{
    int	temp;

    temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}


static int	sort_tab(int *tab, int size)
{
    int i;
	int j;

	i =0;
    while (i < size - 1)          
    {
		j = 0;
        while (j < size - 1 - i)   
        {
            if (tab[j] > tab[j + 1])
            {
                ft_swap(&tab[j], &tab[j + 1]);
            }
			j++;
        }
		i++;
    }
	return (0);
}


static int	copy_tab(int *tab_a, int *tab_sort, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		tab_sort[i] = tab_a[i];
		i++;
	}
	return (0);
}

static int	fill_tab(int **tab_chunk, int *tab_sort, int chunk_size, int chunk_len)
{
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	while (j < chunk_len)
	{
		i = 0;
		while (i < chunk_size)
		{
			tab_chunk[j][i] = tab_sort[k];
			i++;
			k++;
		}
		j++;
	}
	return (0);
}

static int	**take_index(int *tab_a, int size_a, int chunk_size)
{
	int *tab_sort;
	int i;
	int index;
	int chunk_len;
	int **tab_chunk;

	tab_sort = ft_calloc(size_a, sizeof(int));
	if (!tab_sort)
		return (0);
	copy_tab(tab_a, tab_sort, size_a);
	sort_tab(tab_sort, size_a);
	chunk_len = size_a / chunk_size;
	tab_chunk = malloc(sizeof(int *) * (chunk_len + 1));
	if (!tab_chunk)
		return (0);
	while (i < chunk_len)
	{
		tab_chunk[i] = ft_calloc(chunk_size, sizeof(int));
		i++;
	}
	fill_tab(tab_chunk, tab_sort, chunk_size, chunk_len);
	free(tab_sort);
	return (tab_chunk);
}



static int	calcul_index(int *tab_sort, int *tab_a, int size_a, int chunk_size)
{
	int i;
	int j;

	j = 0;
	while (j < size_a)
	{
		i = 0;
		while (i < chunk_size)
		{
			if (tab_sort[i] == tab_a[j])
				return (j);
			i++;
		}
		j++;
	}
	//ft_printf("j = %d\n", j);
	return (j);
}


static int	find_max(int *tab_sort, int *tab_b, int size_b, int chunk_size)
{
	int i;
	int j;

	i = chunk_size - 1;
	while (i > -1)
	{
		j = 0;
		while (j < size_b)
		{
			if (tab_sort[i] == tab_b[j])
				return (j);
			j++;
		}
		i--;
	}
	// ft_printf("j = %d\n", j);
	return (j);
}

static int	find_index(int *shunk, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (shunk[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static int	find_max_value(int *tab_b, int size_b)
{
	int	i;
	int	max;

	i = 0;
	max = tab_b[0];
	while (i < size_b)
	{
		if (tab_b[i] > max)
			max = tab_b[i];
		i++;
	}
	return (max);
}

static int isqrt(int n)
{
    int x = 0;
    while ((x + 1) * (x + 1) <= n)
        x++;
    return (x);
}

static int	push_max_from_b(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int max;
	int index;
	int count;

	max = find_max_value(tab_b, *size_b);
	index = find_index(tab_b, *size_b, max);
	count = 0;
	if (index <= *size_b / 2)
	{
		while (index-- > 0)
			count += rb(tab_b, *size_b);
	}
	else
	{
		index = *size_b - index;
		while (index-- > 0)
			count += rrb(tab_b, *size_b);
	}
	count += pa(tab_a, tab_b, size_a, size_b);
	return (count);
}

int chunk_sort_opt(int *tab_a, int size_a)
{
	int i;
    int max_chunk;
	int chunk_size;
	int chunk_len;
	int size_b;
	int count;
	int **tab_sort;
	int *tab_b;
	int k;
	int j;
	int y;

	chunk_size = isqrt(size_a);
	GREEN;
	//ft_printf("isqrt =%d\n", chunk_size);
	RESET;
	size_b = 0;
	count = 0;
	chunk_len = size_a / chunk_size;
 	tab_b = ft_calloc(size_a, sizeof(int));
 	if (!tab_b)
		return (0);
	tab_sort = take_index(tab_a, size_a, chunk_size);
	//afficherTableau(chunk_len, chunk_size, tab_sort);
	j = 0;
	while (j < chunk_len)
	{
		i = 0;
		while (i < chunk_size)
		{
			k = calcul_index(tab_sort[j], tab_a, size_a, chunk_size);
			y = 0;
			if (k > (size_a / 2))
			{
				k = size_a - k;
				while (y < k)
				{
					count += rra(tab_a, size_a);
					y++;
				}
			}
			else
			{
				while (y < k)
				{
					count += ra(tab_a, size_a);
					y++;
				}
			}
			count += pb(tab_a, tab_b, &size_a, &size_b);
			i++;
		}
		j++;
	}
	while (size_b > 0)
		count += push_max_from_b(tab_a, tab_b, &size_a, &size_b);
	free(tab_b);
	return (count);
}

