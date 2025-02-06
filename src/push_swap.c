/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:41:34 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/06 18:03:30 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushSwap.h"

int	main(int argc, char *argv[])
{
	t_list	*inputList;
	//t_list	*tempList;

	if (argc < 2 && *argv == NULL)
	{
		write(1, "\nfalha", 7);
		return (1);
	}
	inputList = NULL;
	validate(++argv, inputList);
	// argv++;
	// while (*argv)
	// {
	// 	printf("%s\n", *argv);
	// 	ft_atoi(*argv);
	// 	ft_lstadd_back(&inputList, ft_lstnew(&argv));
	// 	content = malloc(sizeof(int));
	// 	*content = (int)num;
	// 	printf("%",(int)inputList->content);
	// 	argv++;
	// 	inputList = inputList->next;
	// }
	write(1, "\nPASSAMO!", 21);

	return (0);
}
