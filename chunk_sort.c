/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:11:47 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/15 16:47:49 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

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

int	calcul_index(int **tab_sort, int *tab_a, int chunk_size)
{
	int count;
	int i;
	int j;
	int k;

	while ()
	{
		
	}

	
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

	chunk_size = 2;
	size_b = 0;
	count = 0;
	chunk_len = size_a / chunk_size;
 	tab_b = ft_calloc(size_a, sizeof(int));
 	if (!tab_b)
		return (0);
	tab_sort = take_index(tab_a, size_a, chunk_size);
	i = 0;
	ft_printf("%s\n", "done");
	j = 0;
	while (j < chunk_len)
	{
		i = 0;
		while (i < chunk_size)
		{
			k = 0;
			while (tab_sort[j][i] != tab_a[k])
				k++;
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
	free(tab_b);
	return (count);
}