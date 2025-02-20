/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:34:01 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:27 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	top_order(t_stack *stack)
{
	if (stack -> index > stack -> next -> index)
		return (1);
	return (0);
}

void	sort_3(t_stack **stack_a)
{
	while (!already_sorted (*stack_a))
	{
		if ((*stack_a)-> index == 1 && (*stack_a)-> next -> index == 2)
			rra(stack_a);
		else if ((*stack_a)-> index == 2 && (*stack_a)-> next -> index == 0)
			ra(stack_a);
		else
			sa(stack_a);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 2;
	while (i > 0)
	{
		if (!((*stack_a)-> index == 0 || (*stack_a)-> index == 1))
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			i--;
		}
	}
	if (top_order (*stack_a) && !top_order (*stack_b))
		ss(stack_a, stack_b);
	else if (top_order(*stack_a))
		sa(stack_a);
	else if (!top_order(*stack_b))
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 2;
	while (i > 0)
	{
		if (!((*stack_a)-> index == 0 || (*stack_a)-> index == 1))
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			i--;
		}
	}
	ft_reset_index(*stack_a);
	sort_3(stack_a);
	if (!top_order(*stack_b))
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
