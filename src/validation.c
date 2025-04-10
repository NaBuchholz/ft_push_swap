/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:25:08 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 13:59:16 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

int	validate(int ac, char **av, t_stack *stack)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < ac)
	{
		if (!av[i][0] || av[i][0] == ' ')
			free_stack(NULL);
		split = ft_split(av[i], ' ');
		if (!split)
			free_stack(NULL);
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
			{
				free_split(split);
				free_stack(NULL);
			}
			j++;
		}
		i++;
	}
	return (1);
}

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
