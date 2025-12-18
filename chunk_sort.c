/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:11:47 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/18 11:04:35 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"

void    ft_swap(int *a, int *b)
{
    int	temp;

    temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}


int	sort_tab(int *tab, int size)
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


int	copy_tab(int *tab_a, int *tab_sort, int size)
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

int	**take_index(int *tab_a, int size_a, int chunk_size)
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

int	calcul_index(int *tab_sort, int *tab_a, int size_a, int chunk_size)
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
	// ft_printf("j = %d\n", j);
	return (j);
}

int	find_max(int *tab_sort, int *tab_b, int size_b, int chunk_size)
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

int isqrt(int n)
{
    int x = 0;
    while ((x + 1) * (x + 1) <= n)
        x++;
    return (x);
}

int chunk_sort(int *tab_a, int size_a)
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
	ft_printf("isqrt =%d\n", chunk_size);
	RESET;
	size_b = 0;
	count = 0;
	chunk_len = size_a / chunk_size;
 	tab_b = ft_calloc(size_a, sizeof(int));
 	if (!tab_b)
		return (0);
	tab_sort = take_index(tab_a, size_a, chunk_size);
	afficherTableau(chunk_len, chunk_size, tab_sort);
	j = 0;
	while (j < chunk_len)
	{
		i = 0;
		while (i < chunk_size)
		{
			k = calcul_index(tab_sort[j], tab_a, size_a, chunk_size);
			y = 0;
			while (y < k)
			{
				count += ra(tab_a, size_a);
				y++;
			}
			count += pb(tab_a, tab_b, &size_a, &size_b);
			i++;
		}
		j++;
	}
	j = chunk_len - 1;
	while (j > -1)
	{
		i = 0;
		while (i < chunk_size)
		{
			k = find_max(tab_sort[j], tab_b, size_b, chunk_size);
			y = 0;
			while (y < k)
			{
				count += rb(tab_b, size_b);
				y++;
			}
			count += pa(tab_a, tab_b, &size_a, &size_b);
			while (y > 0)
			{
				count += rrb(tab_b, size_b);
				y--;
			}
			i++;
		}
		j--;
	}
	free(tab_b);
	return (count);
}