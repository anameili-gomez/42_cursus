/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:33:58 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:23:18 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b, int bit_size, int j)
{
	int	b_size;

	b_size = ft_stacksize(*stack_b);
	while (b_size-- && j <= bit_size && !already_sorted(*stack_a))
	{
		if (((*stack_b)->index >> j) & 1)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
	if (already_sorted(*stack_a))
	{
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

void	main_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	int		bit_size;
	int		j;
	size_t	a_size;

	bit_size = 0;
	while (size > 1 && ++bit_size)
		size = size / 2;
	j = -1;
	while (++j <= bit_size)
	{
		a_size = ft_stacksize(*stack_a);
		while (a_size-- && !already_sorted(*stack_a))
		{
			if (((*stack_a)-> index >> j) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		sort_stack_b(stack_a, stack_b, bit_size, j + 1);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
