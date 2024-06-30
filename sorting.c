/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:01:16 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 16:21:52 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elements(char *str, int *arry, int size)
{
	int	tmp;

	if (size > 1)
	{
		tmp = arry[0];
		arry[0] = arry[1];
		arry[1] = tmp;
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
}

void	sort_three(t_stack_node *stack)
{
	if (stack->stack_a[2] != 2)
	{
		if (stack->stack_a[0] == 2)
			rotate_elements(stack->stack_a, stack->size_a, "ra", "a");
		else
			rotate_elements(stack->stack_a, stack->size_a, "rra", "a");
	}
	if (stack->stack_a[0] > stack->stack_a[1])
		swap_elements("sa", stack->stack_a, stack->size_a);
}

void	sort_four_five(t_stack_node *stack)
{
	while (stack->size_b <= 1)
	{
		if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
			push_elements("pb", stack);
		else
			rotate_elements(stack->stack_a, stack->size_a, "ra", "a");
	}
	if (stack->stack_b[0] == 0)
		swap_elements("sb", stack->stack_b, stack->size_b);
	if (stack->stack_a[2] != 4)
	{
		if (stack->stack_a[0] == 4)
			rotate_elements(stack->stack_a, stack->size_a, "ra", "a");
		else
			rotate_elements(stack->stack_a, stack->size_a, "rra", "a");
	}
	if (stack->stack_a[0] > stack->stack_a[1])
		swap_elements("sa", stack->stack_a, stack->size_a);
	push_elements("pa", stack);
	push_elements("pa", stack);
}
