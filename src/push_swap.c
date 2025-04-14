/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:41:34 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/14 17:35:56 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static void	copy_values(int *copy, int *val, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		copy[i] = val[i];
}

static void	calculate_ranks(int *copy, int *ranks, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		ranks[i] = 0;
		while (++j < size)
			if (copy[j] < copy[i] || (copy[j] == copy[i] && j < i))
				ranks[i]++;
	}
}

static void	normalize_stack(t_stack *stack)
{
	int	*copy;
	int	*ranks;
	int	i;

	copy = (int *)malloc(sizeof(int) * stack->size);
	ranks = (int *)malloc(sizeof(int) * stack->size);
	if (!copy || !ranks)
	{
		free(copy);
		free(ranks);
		return ;
	}
	copy_values(copy, stack->val, stack->size);
	calculate_ranks(copy, ranks, stack->size);
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

	if (argc < 2 || !*argv[1])
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
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
