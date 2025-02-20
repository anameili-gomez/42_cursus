/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:45 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:27 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	**initialise_stack(void)
{
	t_stack	**stack;

	stack = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	return (stack);
}

int	main(int ac, char **av)
{
	char	**args;
	size_t	numbers;
	t_stack	**stack_a;
	t_stack	**stack_b;

	args = get_args(ac, av);
	numbers = ft_get_numbers(args);
	stack_a = initialise_stack();
	*stack_a = get_stack(numbers, args, stack_a);
	if (numbers == 1 || already_sorted(*stack_a))
		exit_wo_error(stack_a, NULL, args);
	stack_b = initialise_stack();
	sort_stack(stack_a, stack_b);
	exit_wo_error(stack_a, stack_b, args);
	return (0);
}
