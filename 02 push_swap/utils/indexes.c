/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:06:25 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:27 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reset_index(t_stack *stack)
{
	while (stack)
	{
		stack -> index = (stack -> index) - 2;
		stack = stack -> next;
	}
}

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack -> number < min -> number)
			min = stack;
		stack = stack -> next;
	}
	return (min);
}

void	ft_get_indexes(t_stack *stack, size_t last_index)
{
	t_stack	*head;
	t_stack	*last_min;
	t_stack	*new_min;
	size_t	current_index;

	last_min = ft_find_min(stack);
	last_min -> index = 0;
	current_index = 1;
	while (current_index <= last_index)
	{
		head = stack;
		new_min = NULL;
		while (head)
		{
			if ((new_min == NULL || head -> number < new_min -> number)
				&& head -> number > last_min -> number)
				new_min = head;
			head = head -> next;
		}
		if (new_min != NULL)
		{
			new_min -> index = current_index++;
			last_min = new_min;
		}
	}
}
