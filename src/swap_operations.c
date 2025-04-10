/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 01:23:45 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static void	sa(t_stack *st_a, int print)
{
	int	temp;

	if (st_a->size < 2)
		return ;
	temp = st_a->val[0];
	st_a->val[0] = st_a->val[1];
	st_a->val[1] = temp;
	if (print == 1)
		ft_printf("sa\n");
}

static void	sb(t_stack *st_b, int print)
{
	int	temp;

	if (st_b->size < 2)
		return ;
	temp = st_b->val[0];
	st_b->val[0] = st_b->val[1];
	st_b->val[1] = temp;
	if (print == 1)
		ft_printf("sb\n");
}

static void	ss(t_stack *st_a, t_stack *st_b, int print)
{
	if (!st_a || !st_b)
		return ;
	sa(st_a, 0);
	sb(st_b, 0);
	if (print == 1)
		ft_printf("ss\n");
}

void	swap(t_stack *st_a, t_stack *st_b, char *op)
{
	if (st_a && ft_strncmp(op, "sa", 3) == 0)
		sa(st_a, 1);
	else if (st_b && ft_strncmp(op, "sb", 3) == 0)
		sb(st_b, 1);
	else if ((st_a && st_b) && ft_strncmp(op, "ss", 3) == 0)
		ss(st_a, st_b, 1);
}
