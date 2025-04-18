/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/14 17:25:05 by nbuchhol         ###   ########.fr       */
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
		temp = (temp * 10) + (*number - '0');
		number++;
	}
	return (temp * sign);
}

void	free_stack(t_stack *stack)
{
	if (stack->val)
		free(stack->val);
	free(stack);
}

void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_stack	*initialize_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->val = (int *)malloc(sizeof(int) * capacity);
	if (!stack->val)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}
