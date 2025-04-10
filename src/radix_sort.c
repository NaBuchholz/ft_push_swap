/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:09:58 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 14:34:26 by nbuchhol         ###   ########.fr       */
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


static void	normalize_stack(t_stack *stack)
{
	int	*copy;
	int	*ranks;
	int	i;
	int	j;

	copy = (int *)malloc(sizeof(int) * stack->size);
	ranks = (int *)malloc(sizeof(int) * stack->size);
	if (!copy || !ranks)
	{
		if (copy)
			free(copy);
		if (ranks)
			free(ranks);
		return ;
	}
	i = -1;
	while (++i < stack->size)
		copy[i] = stack->val[i];
	i = -1;
	while (++i < stack->size)
	{
		j = -1;
		ranks[i] = 0;
		while (++j < stack->size)
			if (copy[j] < copy[i] || (copy[j] == copy[i] && j < i))
				ranks[i]++;
	}
	i = -1;
	while (++i < stack->size)
		stack->val[i] = ranks[i];
	free(copy);
	free(ranks);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bit;

	normalize_stack(stack_a);
	max_bit = max_bits(stack_a);
	size = stack_a->size;
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->val[0] >> i) & 1) == 1)
				rotate(stack_a, stack_b, "ra");
			else
				push(stack_a, stack_b, "pb");
			j++;
		}
		while (stack_b->size != 0)
			push(stack_a, stack_b, "pa");
		i++;
	}
}
