/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:28:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/11 15:18:54 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>


int	insertion_sort(int *tab_a, int size)
{
	int		i;
	int 	*tab_b;
	int 	size_a;
	int		size_b;
	int		count;

	tab_b = ft_calloc(size + 1, sizeof(int));
	if (!tab_b)
		return (0);
	size_a = size;
	size_b = 0;
	count = 0;
	while (size_a > 0)
	{
		
	}
	free(tab_b);
	return (count);
}

