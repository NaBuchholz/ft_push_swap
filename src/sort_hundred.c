/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:08:13 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/13 20:15:13 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int start,
		int end)
{
	int	count;

	count = 0;
	while (count < end - start && stack_a->size > 0)
	{
		if (stack_a->val[0] >= start && stack_a->val[0] < end)
		{
			push(stack_a, stack_b, "pb");
			count++;
		}
		else
			rotate(stack_a, stack_b, "ra");
	}
}

static int	find_max_position(t_stack *stack)
{
	int	max;
	int	pos;
	int	i;

	max = INT_MIN;
	pos = -1;
	i = 0;
	while (i < stack->size)
	{
		if (stack->val[i] > max)
		{
			max = stack->val[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	move_to_top_b(t_stack *stack_a, t_stack *stack_b, int pos)
{
	if (pos <= stack_b->size / 2)
	{
		while (pos-- > 0)
			rotate(stack_a, stack_b, "rb");
	}
	else
	{
		while (pos++ < stack_b->size)
			rotate_re(stack_a, stack_b, "rrb");
	}
}

static void	push_max_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max_pos;

	max_pos = find_max_position(stack_b);
	move_to_top_b(stack_a, stack_b, max_pos);
	push(stack_a, stack_b, "pa");
}

void	sort_hundred(t_stack *stack_a, t_stack *stack_b)
{
	int chunk_size;
	int i;
	int chunk_count;

	chunk_count = 5;
	chunk_size = stack_a->size / chunk_count;

	i = 0;
	while (i < chunk_count)
	{
		push_chunk_to_b(stack_a, stack_b, i * chunk_size, (i + 1) * chunk_size);
		i++;
	}

	while (stack_a->size > 0)
		push(stack_a, stack_b, "pb");

	while (stack_b->size > 0)
		push_max_to_a(stack_a, stack_b);
}