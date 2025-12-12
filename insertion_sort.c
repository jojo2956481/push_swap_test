/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:28:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/12 09:46:06 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>


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
