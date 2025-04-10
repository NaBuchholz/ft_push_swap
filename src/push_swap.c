/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:41:34 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 14:09:40 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = initialize_stack(argc - 1);
	stack_b = initialize_stack(argc - 1);
	if (!stack_a || !stack_b)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (ft_printf("Error\n"), 1);
	}
	if (!parse_args(argc, argv, stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (ft_printf("Error\n"), 1);
	}
	if (!is_sorted(stack_a))
		sort_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
