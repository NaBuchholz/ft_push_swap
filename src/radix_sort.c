/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:09:58 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 20:26:14 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((stack_a->val[0] >> bit) & 1) == 1)
			rotate(stack_a, stack_b, "ra");
		else
			push(stack_a, stack_b, "pb");
		j++;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size;
	int	max_bits;

	size = stack_a->size;
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		process_bit(stack_a, stack_b, i, size);
		while (stack_b->size != 0)
			push(stack_a, stack_b, "pa");
		i++;
	}
}
