/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:25:08 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/06 18:28:41 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

int	validate(char **argv, t_list *inputList)
{
	int		i;
	long	temp;

	i= 0;
	while (*argv)
	{
		temp = ft_atol(*argv);
		if (temp > INT_MAX || temp < INT_MIN)
			return (1);
		argv++;
	}
	inputList = NULL;
	return (0);
}
