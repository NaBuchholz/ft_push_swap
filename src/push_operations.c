/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 01:34:55 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static void	pa(t_stack *st_a, t_stack *st_b, int print)
{
	if (st_b->size == 0)
		return ;
	ft_memmove(st_a->val + 1, st_a->val, sizeof(int) * st_a->size);
	st_a->val[0] = st_b->val[0];
	ft_memmove(st_b->val, st_b->val + 1, sizeof(int) * st_b->size - 1);
	st_a->size++;
	st_b->size--;
	if (print == 1)
		ft_printf("pa\n");
}

static void	pb(t_stack *st_a, t_stack *st_b, int print)
{
	if (st_a->size == 0)
		return ;
	ft_memmove(st_b->val + 1, st_b->val, sizeof(int) * st_b->size);
	st_b->val[0] = st_a->val[0];
	ft_memmove(st_a->val, st_a->val + 1, sizeof(int) * (st_a->size - 1));
	st_b->size++;
	st_a->size--;
	if (print == 1)
		ft_printf("pb\n");
}

void	push(t_stack *st_a, t_stack *st_b, char *op)
{
	if (!st_a || !st_b)
		return ;
	if (ft_strncmp(op, "pa", 3) == 0)
		pa(st_a, st_b, 1);
	else if (ft_strncmp(op, "pb", 3) == 0)
		pb(st_a, st_b, 1);
}
