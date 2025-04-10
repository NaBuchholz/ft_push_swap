/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:09:58 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 04:34:47 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static int	max_bits(t_stack *stack)
{
	int	max_val;
	int	i;
	int	bits;

	max_val = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->val[i] > max_val)
			max_val = stack->val[i];
		i++;
	}
	bits = 0;
	while (max_val > 0)
	{
		max_val >>= 1;
		bits++;
	}
	return (bits);
}

static int	get_rank(t_stack *stack, int value, int pos)
{
	int	rank;
	int	i;

	rank = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->val[i] < value)
			rank++;
		i++;
	}
	i = 0;
	while (i < pos)
	{
		if (stack->val[i] == value)
			rank++;
		i++;
	}
	return (rank);
}

static int	*init_normalized_array(int size)
{
	int	*normalized;

	normalized = (int *)malloc(sizeof(int) * size);
	return (normalized);
}
