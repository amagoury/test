/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:29:09 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 15:22:52 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	stack;

	if (ac < 2)
		return (0);
	valid_args(ac, av);
	joinig(ac, av, &stack);
	its_numbers(&stack);
	dupchecker(&stack, 0);
	its_index(&stack);
	if (stack.size_a == 2 && stack.stack_a[0] > stack.stack_a[1])
		swap_elements("sa", stack.stack_a, stack.size_a);
	else if (stack.size_a == 3)
		sort_three(&stack);
	else if (stack.size_a == 4 || stack.size_a == 5)
		sort_four_five(&stack);
	else
		apply_radix_sort(&stack);
	return (0);
}
