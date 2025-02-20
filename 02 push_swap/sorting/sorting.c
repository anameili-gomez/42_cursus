/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:47:15 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:23:18 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_stacksize(t_stack *lst)
{
	int	n;

	n = 0;
	while (lst != NULL)
	{
		n++;
		lst = lst -> next;
	}
	return (n);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	size_t	size;

	size = ft_stacksize(*stack_a);
	if (size <= 5)
		simple_sort(stack_a, stack_b, size);
	else
		main_sort(stack_a, stack_b, size + 1);
}
