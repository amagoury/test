/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:10:29 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 16:14:46 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h> 
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack_node
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	char	*args;
}		t_stack_node;

void	valid_args(int ac, char **av);
void	dupchecker(t_stack_node *stack, int i);
void	stack_int(int ac, char **av, t_stack_node *stack);
int		stack_size(char **array);
int		is_stack_sort(t_stack_node *stack, int a);
void	joinig(int ac, char **av, t_stack_node *stack);
void	its_error(t_stack_node *stack, char *msg);
int		ft_atoi2(const char *str, t_stack_node *stack);
void	its_numbers(t_stack_node *stack);
void	its_index(t_stack_node *stack);
void	valid_args(int ac, char **av);
void	swap_elements(char *str, int *arry, int size);
void	rotate_a(int *arry, int size);
void	rev_rotate(int *arry, int size);
void	rotate_elements(int *array, int size, char *direction, char *list);
void	sort_three(t_stack_node *stack);
void	sort_four_five(t_stack_node *stack);
void	push_elements(char *str, t_stack_node *stack);
void	push_pa(t_stack_node *stack);
void	push_pb(t_stack_node *stack);
void	radix_sort_stack_b(t_stack_node *stack,
			int b_size, int bit_size, int j);
void	apply_radix_sort(t_stack_node *stack);

#endif
