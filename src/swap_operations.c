/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 01:19:09 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static void	sa(t_stack *stack_a, int print)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->val[0];
	stack_a->val[0] = stack_a->val[1];
	stack_a->val[1] = temp;
	if (print == 1)
		ft_printf("sa\n");
}

static void	sb(t_stack *stack_b, int print)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->val[0];
	stack_b->val[0] = stack_b->val[1];
	stack_b->val[1] = temp;
	if (print == 1)
		ft_printf("sb\n");
}

static void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (!stack_a || !stack_b)
		return ;
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print == 1)
		ft_printf("ss\n");
}

void	swap(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (stack_a && ft_strncmp(op, "sa", 3) == 0)
		sa(stack_a, 1);
	else if (stack_b && ft_strncmp(op, "sb", 3) == 0)
		sb(stack_b, 1);
	else if ((stack_a && stack_b) && ft_strncmp(op, "ss", 3) == 0)
		ss(stack_a, stack_b, 1);
}
