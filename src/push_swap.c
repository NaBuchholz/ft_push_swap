/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:41:34 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 20:06:53 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"


static void	normalize_stack(t_stack *stack)
{
	int	*copy;
	int	*ranks;
	int	i;
	int	j;

	copy = (int *)malloc(sizeof(int) * stack->size);
	ranks = (int *)malloc(sizeof(int) * stack->size);
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = initialize_stack(argc - 1);
	stack_b = initialize_stack(argc - 1);
	if (!stack_a || !stack_b)
		exit_error(stack_a, stack_b);
	if (!parse_args(argc, argv, stack_a))
		exit_error(stack_a, stack_b);
	normalize_stack(stack_a);
	if (!is_sorted(stack_a))
		sort_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
