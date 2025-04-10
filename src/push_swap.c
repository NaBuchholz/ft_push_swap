/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:41:34 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 13:32:09 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

int	main(int argc, char *argv[])
{
	t_stack	*input_list;

	if (argc < 2 && *argv == NULL)
		return (ft_printf("Error\n"), 1);
	validate(argc, ++argv, input_list);
	write(1, "\nPASSAMO!", 21);

	return (0);
}
