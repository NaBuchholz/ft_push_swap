/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:34:05 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/04/10 13:56:44 by nbuchhol         ###   ########.fr       */
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

int		validate(int ac, char **av, t_stack *stack);
long	ft_atol(char *number);
void	free_split(char **split);
void	swap(t_stack *st_a, t_stack *st_b, char *op);
void	push(t_stack *st_a, t_stack *st_b, char *op);
void	rotate(t_stack *st_a, t_stack *st_b, char *op);
void	rotate_re(t_stack *st_a, t_stack *st_b, char *op);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif
