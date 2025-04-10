/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:34:05 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 14:26:50 by nbuchhol         ###   ########.fr       */
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
	int	*val;
	int	size;
	int	capacity;
}	t_stack;

long	ft_atol(char *number);
void	free_split(char **split);
int		parse_args(int argc, char **argv, t_stack *stack_a);
void	swap(t_stack *st_a, t_stack *st_b, char *op);
void	push(t_stack *st_a, t_stack *st_b, char *op);
void	rotate(t_stack *st_a, t_stack *st_b, char *op);
void	rotate_re(t_stack *st_a, t_stack *st_b, char *op);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		has_duplicate(t_stack *stack, int num);

#endif
