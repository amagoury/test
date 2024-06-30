/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:11:36 by aishamagour       #+#    #+#             */
/*   Updated: 2024/06/30 16:11:27 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valid_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0] || (av[i][0] && av[i][0] == ' '))
			its_error(NULL, "ERROR\n");
		while (av[i][j] != '\0')
		{
			if ((!(ft_isdigit(av[i][j])) && (av[i][j] != ' ')
					&& (av[i][j] != '-' && av[i][j] != '+'))
				|| (av[i][j] == '-' && av[i][j + 1] == '\0')
				|| (av[i][j] == '+' && av[i][j + 1] == '\0')
				|| (av[i][j] == '-' && av[i][j + 1] == ' ')
				|| (av[i][j] == '+' && av[i][j + 1] == ' '))
				its_error(NULL, "ERROR\n");
			j++;
		}
	}
}

void	stack_int(int ac, char **av, t_stack_node *stack)
{
	int	i;

	i = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	while (--ac)
	{
		if (count_word(av[i + 1], ' '))
			stack->size_a += count_word(av[i + 1], ' ');
		else
			stack->size_a++;
		stack->size_b = stack->size_a;
		i++;
		stack->stack_a = malloc(stack->size_a * sizeof(int));
		if (stack->stack_a == NULL)
			its_error(stack, "ERROR\n");
		stack->stack_b = malloc(stack->size_b * sizeof(int));
		if (stack->stack_b == NULL)
			its_error(stack, "ERROR\n");
	}
}

void	joinig(int ac, char **av, t_stack_node *stack)
{
	char	*stack1;
	char	*tmp;
	int		i;

	stack1 = ft_strdup("");
	if (!stack1)
		its_error(stack, "Error\n");
	i = 1;
	while (i < ac)
	{
		tmp = ft_strjoin(stack1, av[i]);
		free(stack1);
		stack1 = tmp;
		if (i < ac - 1)
		{
			tmp = ft_strjoin(stack1, " ");
			free(stack1);
			stack1 = tmp;
		}
		if (!stack1)
			its_error(stack, "Error\n");
		i++;
	}
	stack->args = stack1;
}

void	its_numbers(t_stack_node *stack)
{
	int		i;
	long	nums;
	char	**tmp;

	tmp = ft_split(stack->args, ' ');
	if (!tmp)
		its_error(stack, "Error\n");
	stack->size_a = stack_size(tmp);
	stack->size_b = 0;
	stack->stack_a = malloc(stack->size_a * sizeof(int));
	if (stack->stack_a == NULL)
		its_error(stack, "ERROR\n");
	stack->stack_b = malloc(stack->size_a * sizeof(int));
	if (stack->stack_b == NULL)
		its_error(stack, "ERROR\n");
	i = -1;
	while (tmp[++i])
	{
		nums = ft_atoi2(tmp[i], stack);
		if (nums > INT_MAX || nums < INT_MIN)
			its_error(stack, "ERROR\n");
		stack->stack_a[i] = (int)nums;
		free(tmp[i]);
	}
	free(tmp);
}

int	ft_atoi2(const char *str, t_stack_node *stack)
{
	unsigned int	i;
	long			sign;
	long			result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_strlen(str + i) > 10)
		its_error(stack, "Error\n");
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= LONG_MAX / 10 && sign == 1)
			return (-1);
		else if (result >= LONG_MAX / 10 && sign == -1)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}
