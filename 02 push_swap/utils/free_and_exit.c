/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:30:36 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:27 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_arguments(char **args)
{
	int	i;
	int	count;

	count = ft_get_numbers(args);
	if (!args)
		return ;
	i = 0;
	while (i <= count)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_stack **stack)
{
	t_stack	*to_free;

	while (*stack)
	{
		to_free = *stack;
		*stack = (*stack)-> next;
		free(to_free);
	}
	*stack = NULL;
	free(stack);
}

void	exit_error(char **args, t_stack **stack)
{
	if (args)
		free_arguments(args);
	if (stack)
		free_stack(stack);
	exit(1);
}

void	exit_wo_error(t_stack **stack_a, t_stack **stack_b, char **args)
{
	if (args)
		free_arguments(args);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	exit(0);
}
