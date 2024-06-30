/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:13:46 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 15:37:49 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pa(t_stack_node *stack)
{
	if (stack->size_b > 0)
	{
		ft_memmove(stack->stack_a + 1, stack->stack_a,
			sizeof(int) * (stack->size_a));
		stack->stack_a[0] = stack->stack_b[0];
		ft_memmove(stack->stack_b, stack->stack_b + 1,
			sizeof(int) * (--stack->size_b));
		stack->size_a++;
	}
}

void	push_pb(t_stack_node *stack)
{
	int	tmp;

	if (stack->size_a <= 0)
		return ;
	tmp = stack->stack_a[0];
	ft_memmove(stack->stack_b + 1, stack->stack_b, sizeof(int)
		* stack->size_b);
	stack->stack_b[0] = tmp;
	stack->size_a--;
	ft_memmove(stack->stack_a, stack->stack_a + 1, sizeof(int)
		* stack->size_a);
	stack->size_b++;
}

void	push_elements(char *str, t_stack_node *stack)
{
	if (!ft_strncmp(str, "pa", 3))
		push_pa(stack);
	else if (!ft_strncmp(str, "pb", 3))
		push_pb(stack);
	ft_putendl_fd(str, 1);
}
