/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:13:11 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/12 17:38:40 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"


int	div_block_2(int *tab_a, int *tab_b, int size_a, int size_b)
{
	int i;
	int n;
	int count;
	int grp;
	int size;

	if (size % 2 != 0)
		grp = 1;
	else
		grp = 0;
	count = 0;
	i = 0;
	size = size_a;
	while (i < size)
	{
		n = 0;
		while (n < 2)
		{
			count += pb(tab_a, tab_b, &size_a, &size_b);
			n++;
		}
		if (tab_b[0] < tab_b[1] && (size_a != 0 || grp != 1))
		{
			count += sb(tab_b, size_b);
		}
		i++;
	}
	ft_printf("%s\n", "finish block 2");
	return (count);
}

int check_index(int *tab, int size_b, int div)
{
	int i;
	int size;
	int pos;
	
	i = 0;
	size = size_b - 1;
	pos = size - div;
	ft_printf("div =  : %d\n", div);
	ft_printf("pos =  : %d\n", tab[size]);
	ft_printf("pos1 =  : %d\n", tab[pos]);
	if (tab[size] > tab[pos])
		return (size - div);
	return (size);
}

int rot_index_first(int *tab_b, int size_b, int index)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < index)
	{
		count += rb(tab_b, size_b);
		i++;
	}
	return (count);
}

int merge_chunk(int *tab_a, int *tab_b, int size_b, int size_a, int nb)
{
	int i;
	int count;
	int div;
	int index;

	div = 2;
	i = 0;
	count = 0;
	index = 0;
	while (i < nb)
	{
		ft_printf("i : %d\n", i);
		if (i == 2)
			div--;
		if (i == 3)
		{
			index = size_b;
			count += rrb(tab_b, size_b);
			count += rot_index_first(tab_b, size_b, index);
			count += pa(tab_a, tab_b, &size_a, &size_b);
			break;
		}
		index = check_index(tab_b, size_b, div);
		ft_printf("index : %d\n", index);
		count += rot_index_first(tab_b, size_b, index);
		count += pa(tab_a, tab_b, &size_a, &size_b);
		index = size_b - index;
		count += rot_index_first(tab_b, size_b, index);
		i++;
	}
	return (count);
}

int	chunk_based(int *tab, int size)
{

	int *tab_b;
	int *tab_a;
	int size_a;
	int size_b;
	int nb;
	int count;

	tab_a = tab;
	tab_b = ft_calloc(size, sizeof(int));
	if (!tab_b)
		return (0);
	size_a = size;
	size_b = 0;
	nb = 4;
	count = 0;
	count += div_block_2(tab_a, tab_b, size_a, size_b);
	size_a = 0;
	size_b = size;
	count += merge_chunk(tab_a, tab_b, size_b, size_a, nb);
	size_a = 4;
	size_b = 4;
	count += merge_chunk(tab_a, tab_b, size_b, size_a, nb);
	
	//display_tape2(tab_b, size_b);
	return (count);
}