/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:34:05 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/13 20:17:01 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*val;
	int	size;
	int	capacity;
}		t_stack;

long	ft_atol(char *number);
t_stack	*initialize_stack(int capacity);
void	free_split(char **split);
int		parse_args(int argc, char **argv, t_stack *stack_a);
void	swap(t_stack *st_a, t_stack *st_b, char *op);
void	push(t_stack *st_a, t_stack *st_b, char *op);
void	rotate(t_stack *st_a, t_stack *st_b, char *op);
void	rotate_re(t_stack *st_a, t_stack *st_b, char *op);
void	sort_hundred(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
void	exit_error(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
int		has_duplicate(t_stack *stack, int num);
int		is_valid_number(char *str);

#endif
