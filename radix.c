/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:13:11 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/15 08:58:01 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"


int	recup_digits(int nb, int digits)
{
	int i;

	i = 0;
	while (i < digits)
	{
		nb = nb / 10;
	}
	return (nb % 10);
}

int	radix(int *tab, int size)
{

		
	return (count);
}