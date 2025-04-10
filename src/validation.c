/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:25:08 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 14:26:36 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"


int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->size <= 1)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->val[i] > stack->val[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int	has_duplicate(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->val[i] == num)
			return (1);
		i++;
	}
	return (0);
}
