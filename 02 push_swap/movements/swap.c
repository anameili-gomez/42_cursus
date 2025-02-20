/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:05:01 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:27 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*stack || !(*stack)-> next)
		return ;
	first = *stack;
	second = first -> next;
	third = second -> next;
	first -> next = third;
	second -> next = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
