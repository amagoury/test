/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:12:19 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 16:16:57 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_radix_sort(t_stack_node *stack)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->size_a;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack->size_a;
		while (size-- > 0)
		{
			if (((stack->stack_a[0] >> j) & 1) == 0)
				push_elements("pb", stack);
			else
				rotate_elements(stack->stack_a, stack->size_a, "ra", "a");
		}
		size = stack->size_b;
		while (size-- > 0)
			push_elements("pa", stack);
	}
	while (stack->size_b != 0)
		push_elements("pa", stack);
}
