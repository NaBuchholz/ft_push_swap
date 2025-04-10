/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:09:58 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 12:50:53 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static int	max_bits(t_stack *stack)
{
	int	max_val;
	int	i;
	int	bits;

	max_val = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->val[i] > max_val)
			max_val = stack->val[i];
		i++;
	}
	bits = 0;
	while (max_val > 0)
	{
		max_val >>= 1;
		bits++;
	}
	return (bits);
}


static void	normalize_stack(t_stack *stack)
{
	int	*copy;
	int	*ranks;
	int	i;
	int	j;

	copy = (int *)malloc(sizeof(int) * stack->size);
	ranks = (int *)malloc(sizeof(int) * stack->size);
	if (!copy || !ranks)
	{
		if (copy)
			free(copy);
		if (ranks)
			free(ranks);
		return ;
	}
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
