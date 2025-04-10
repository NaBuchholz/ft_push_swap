/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:32:15 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 20:25:24 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->val[0];
	b = stack_a->val[1];
	c = stack_a->val[2];
	if (a > b && b < c && a < c)
		swap(stack_a, NULL, "sa");
	else if (a > b && b > c)
	{
		swap(stack_a, NULL, "sa");
		rotate_re(stack_a, NULL, "rra");
	}
	else if (a > b && b < c && a > c)
		rotate(stack_a, NULL, "ra");
	else if (a < b && b > c && a < c)
	{
		swap(stack_a, NULL, "sa");
		rotate(stack_a, NULL, "ra");
	}
	else if (a < b && b > c && a > c)
		rotate_re(stack_a, NULL, "rra");
}

static int	find_min_position(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

	min = INT_MAX;
	pos = -1;
	i = 0;
	while (i < stack->size)
	{
		if (stack->val[i] < min)
		{
			min = stack->val[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	move_min_to_top(t_stack *stack_a, int pos)
{
	if (pos <= stack_a->size / 2)
	{
		while (pos-- > 0)
			rotate(stack_a, NULL, "ra");
	}
	else
	{
		while (pos++ < stack_a->size)
			rotate_re(stack_a, NULL, "rra");
	}
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;
	int	count;

	count = 0;
	while (count < 2)
	{
		pos = find_min_position(stack_a);
		move_min_to_top(stack_a, pos);
		push(stack_a, stack_b, "pb");
		count++;
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		push(stack_a, stack_b, "pa");
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->val[0] > stack_a->val[1])
			swap(stack_a, stack_b, "sa");
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
