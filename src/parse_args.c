/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:18:11 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/15 11:31:32 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

static int	process_number(t_stack *stack_a, char *str)
{
	long	num;

	if (!is_valid_number(str))
		return (0);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN || has_duplicate(stack_a, (int)num))
		return (0);
	stack_a->val[stack_a->size++] = (int)num;
	return (1);
}

static int	process_split(t_stack *stack_a, char **split)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (split[j])
	{
		count++;
		j++;
	}
	if (stack_a->size + count > stack_a->capacity)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!process_number(stack_a, split[j]))
			return (0);
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0 || argv[i][0] == '\0')
			return (0);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		if (!process_split(stack_a, split))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (1);
}
