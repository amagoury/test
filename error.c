/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:33:48 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 15:21:32 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	its_error(t_stack_node *stack, char *msg)
{
	if (msg)
		write (2, msg, ft_strlen(msg));
	if (stack != NULL)
	{
		if (stack->stack_a != NULL)
			free(stack->stack_a);
		if (stack->stack_b != NULL)
			free(stack->stack_b);
		if (stack->args != NULL)
			free(stack->args);
	}
	exit(0);
}
