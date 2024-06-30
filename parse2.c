/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:00:10 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 15:57:22 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sort(t_stack_node *stack, int a)
{
	int	i;

	if (a == 1)
	{
		i = 0;
		while (i < (stack->size_a - 1))
		{
			if (stack->stack_a[i] > stack->stack_a[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (stack->size_b - 1))
		{
			if (stack->stack_b[i] > stack->stack_b[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

void	dupchecker(t_stack_node *stack, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stack->size_a)
		{
			j = i + 1;
			while (j < stack->size_a)
			{
				if (stack->stack_a[i] == stack->stack_a[j])
				{
					its_error(stack, "Error\n");
				}
				j++;
			}
			i++;
		}
	}
	if (is_stack_sort(stack, 1))
		its_error(stack, NULL);
}

void	its_index(t_stack_node *stack)
{
	int	i;
	int	j;
	int	k;
	int	*new_index;

	i = -1;
	new_index = malloc(stack->size_a * sizeof(int));
	if (new_index == NULL)
		its_error(stack, "ERROR\n");
	while (++i < stack->size_a)
	{
		k = 0;
		j = -1;
		while (++j < stack->size_a)
		{
			if (stack->stack_a[i] > stack->stack_a[j])
				k++;
		}
		new_index[i] = k;
	}
	i = stack->size_a;
	while (i--)
		stack->stack_a[i] = new_index[i];
	free(new_index);
}

int	stack_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
