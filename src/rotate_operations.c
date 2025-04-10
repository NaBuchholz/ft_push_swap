/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 01:53:31 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static void	ra(t_stack *st_a, int print)
{
	int	temp;
	int	i;

	if (st_a->size < 2)
		return ;
	temp = st_a->val[0];
	i = 0;
	while (i < st_a->size - 1)
	{
		st_a->val[i] = st_a->val[i + 1];
		i++;
	}
	st_a->val[st_a->size - 1] = temp;
	if (print == 1)
		ft_printf("ra\n");
}

static void	rb(t_stack *st_b, int print)
{
	int	temp;
	int	i;

	if (st_b->size < 2)
		return ;
	temp = st_b->val[0];
	i = 0;
	while (i < st_b->size - 1)
	{
		st_b->val[i] = st_b->val[i + 1];
		i++;
	}
	st_b->val[st_b->size - 1] = temp;
	if (print == 1)
		ft_printf("rb\n");
}

static void	rr(t_stack *st_a, t_stack *st_b, int print)
{
	if (!st_a || !st_b)
		return ;
	ra(st_a, 0);
	rb(st_b, 0);
	if (print == 1)
		ft_printf("rr\n");
}

void	rotate(t_stack *st_a, t_stack *st_b, char *op)
{
	if (st_a && ft_strncmp(op, "ra", 3) == 0)
		ra(st_a, 1);
	else if (st_b && ft_strncmp(op, "rb", 3) == 0)
		rb(st_b, 1);
	else if ((st_a && st_b) && ft_strncmp(op, "rr", 3) == 0)
		rr(st_a, st_b, 1);
}
