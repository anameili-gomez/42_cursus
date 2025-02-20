/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:49:20 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:27 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	double_number(int n, t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current -> next)
	{
		if (current -> number == n)
			return (1);
		current = current -> next;
	}
	return (0);
}

size_t	ft_strdigit(char *s)
{
	size_t	i;

	i = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

int	other_character(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	validate_and_convert(char *number, char **args, t_stack **stack)
{
	long	n;

	if (other_character(number))
	{
		ft_printf("Error\n");
		exit_error(args, stack);
	}
	n = ft_atol(number);
	if (ft_strdigit(number) > 11 || (n > INT_MAX) || (n < INT_MIN))
	{
		ft_printf("Error\n");
		exit_error(args, stack);
	}
	if (double_number((int)n, stack))
	{
		ft_printf("Error\n");
		exit_error(args, stack);
	}
	return ((int) n);
}

int	already_sorted(t_stack *stack)
{
	t_stack	*prev;

	while (stack && stack -> next)
	{
		prev = stack;
		stack = stack -> next;
		if (prev -> number > stack -> number)
			return (0);
	}
	return (1);
}
