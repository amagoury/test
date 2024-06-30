/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:17:51 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 15:32:59 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *arry, int size)
{
	int	tmp;
	int	i;

	i = 0;
	if (size <= 1)
		return ;
	tmp = arry[0];
	while (i < size - 1)
	{
		arry[i] = arry[i + 1];
		i++;
	}
	arry[size - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rev_rotate(int *arry, int size)
{
	int	tmp;
	int	i;

	i = size - 2;
	if (size <= 1)
		return ;
	tmp = arry[size -1];
	while (i >= 0)
	{
		arry[i + 1] = arry[i];
		i--;
	}
	arry[0] = tmp;
	write(1, "rra\n", 4);
}

void	rotate_elements(int *array, int size, char *direction, char *list)
{
	(void)list;
	if (ft_strncmp(direction, "ra", 2) == 0)
		rotate_a(array, size);
	else if (ft_strncmp(direction, "rra", 4) == 0)
		rev_rotate(array, size);
}
