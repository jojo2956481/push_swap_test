/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:24:34 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/16 13:06:25 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


int	sa(int *a, int size_a);
int	pa(int *a, int *b, int *size_a, int *size_b);
int	ra(int *a, int size_a);
int	rra(int *a, int size_a);
int	sb(int *b, int size_b);
int	pb(int *a, int *b, int *size_a, int *size_b);
int	rb(int *b, int size_b);
int	rrb(int *b, int size_b);
int	ss(int *b, int *a, int size_a, int size_b);
int	rr(int *b, int *a, int size_b, int size_a);
int	rrr(int *b, int *a, int size_b, int size_a);
int	bubble_sort(int *tab, int size);
int	ft_intlen(int n);
int	display(int *tab, int size, int k);
int	insertion_sort(int *tab_a, int size_a);
int display_tape(int *tab_a, int *tab_b, int size_a, int size_b);
int display_tape1(int *tab_a, int size_a);
int	*ft_intdup(int *tab, int size);
int display_tape2(int *tab_a, int size_a);
int chunk_sort(int *tab_a, int size_a);
int chunk_sort_test(int *tab_a, int size_a);


#endif