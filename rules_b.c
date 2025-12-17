/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:17:20 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/17 12:42:28 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"


// Swap the first two elements at the top of stack b
int	sb(int *b, int size_b)
{
	int	temp;

	if (size_b <= 1)
		return (0);
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	display_tape2(b, size_b);
	ft_printf("%s\n", "sb");
	return (1);
}

// Take the first element at the top of a and put it at the top of b.
int pb(int *a, int *b, int *size_a, int *size_b)
{
	int i;

	if (*size_a <= 0)
		return 0;
	for (i = *size_b; i > 0; i--)
		b[i] = b[i - 1];
	b[0] = a[0];
	for (i = 0; i < *size_a - 1; i++)
		a[i] = a[i + 1];
	(*size_a)--;
	(*size_b)++;
	display_tape(a, b, *size_a, *size_b);
	ft_printf("%s\n", "pb");
	return (1);
}

// Shift up all elements of stack b by one.
int	rb(int *b, int size_b)
{
	int	temp;
	int	i;

	if (size_b < 2)
		return (0);
	temp = b[0];
	i = 0;
	while (i < size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = temp;
	ft_printf("%s\n", "rb");
	display_tape2(b, size_b);
	return (1);
}

// Shift down all elements of stack b by one.
int	rrb(int *b, int size_b)
{
	int	temp;
	int	i;

	if (size_b < 2)
		return (0);
	temp = b[size_b - 1];
	i = size_b - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	ft_printf("%s\n", "rrb");
	display_tape2(b, size_b);
	return (1);
}

