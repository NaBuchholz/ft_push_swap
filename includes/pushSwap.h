/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:34:05 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/09 23:54:10 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int	*values;
	int	size;
	int	capacity;
}	t_stack;

int		validate(char **argv, t_list *inputList);
long	ft_atol(char *number);
// void	sa(t_stack *stack_a, int print);
// void	sb(t_stack *stack_b, int print);
// void	ss(t_stack *stack_a, t_stack *stack_b, int print);
// void	pa(t_stack *stack_a, t_stack *stack_b, int print);
// void	pb(t_stack *stack_a, t_stack *stack_b, int print);
// void	ra(t_stack *stack_a, int print);
// void	rb(t_stack *stack_b, int print);
// void	rr(t_stack *stack_a, t_stack *stack_b, int print);
// void	rra(t_stack *stack_a, int print);
// void	rrb(t_stack *stack_b, int print);
// void	rrr(t_stack *stack_a, t_stack *stack_b, int print);

#endif
