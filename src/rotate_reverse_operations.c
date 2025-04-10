/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:54:07 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 12:46:44 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static void	rra(t_stack *st_a, int print)
{
	int	temp;
	int	i;

	if (st_a->size < 2)
		return ;
	temp = st_a->val[st_a->size - 1];
	i = st_a->size - 1;
	while (i > 0)
	{
		st_a->val[i] = st_a->val[i - 1];
		i--;
	}
	st_a->val[0] = temp;
	if (print == 1)
		ft_printf("rra\n");
}

static void	rrb(t_stack *st_b, int print)
{
	int	temp;
	int	i;

	if (st_b->size < 2)
		return ;
	temp = st_b->val[st_b->size - 1];
	i = st_b->size - 1;
	while (i > 0)
	{
		st_b->val[i] = st_b->val[i - 1];
		i--;
	}
	st_b->val[0] = temp;
	if (print == 1)
		ft_printf("rrb\n");
}

static void	rrr(t_stack *st_a, t_stack *st_b, int print)
{
	if (!st_a || !st_b)
		return ;
	rra(st_a, 0);
	rrb(st_b, 0);
	if (print == 1)
		ft_printf("rrr\n");
}

void	rotate_re(t_stack *st_a, t_stack *st_b, char *op)
{
	if (st_a && ft_strncmp(op, "rra", 4) == 0)
		rra(st_a, 1);
	else if (st_b && ft_strncmp(op, "rrb", 4) == 0)
		rrb(st_b, 1);
	else if ((st_a && st_b) && ft_strncmp(op, "rrr", 4) == 0)
		rrr(st_a, st_b, 1);
}
