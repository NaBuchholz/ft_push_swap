/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 04:05:45 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

long	ft_atol(char *number)
{
	long	temp;
	int		sign;

	if (number == NULL)
		return (0);
	sign = 1;
	if (*number == '-')
	{
		sign = -1;
		number++;
	}
	else if (*number == '+')
		number++;
	temp = 0;
	while (*number >= '0' && *number <= '9' && *number)
	{
		temp = (temp * 10) + (*number - '0' );
		number++;
	}
	return (temp * sign);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->val)
			free(stack->val);
		free(stack);
	}
}
