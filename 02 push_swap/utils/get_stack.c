/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:05:30 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:27 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*copy_args(char *av)
{
	int		i;
	int		n;
	char	*number;

	n = 0;
	while (av[n])
		n++;
	number = (char *)malloc(sizeof(char) * (n + 1));
	if (!number)
		return (NULL);
	i = 0;
	while (av[i])
	{
		number[i] = av[i];
		i++;
	}
	number[i] = '\0';
	return (number);
}

char	**get_args(int ac, char **av)
{
	char	**args;
	int		i;

	args = NULL;
	if (ac < 2)
		exit_error(NULL, NULL);
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		args = (char **)malloc((sizeof(char *)) * ac);
		i = 1;
		while (i < ac)
		{
			args[i - 1] = copy_args(av[i]);
			if (!args[i - 1])
				exit_error(args, NULL);
			i++;
		}
		args[i - 1] = NULL;
	}
	return (args);
}

size_t	ft_get_numbers(char **args)
{
	size_t	n;

	n = 0;
	while (args[n])
		n++;
	return (n);
}

t_stack	*get_new_node(void)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack) * 1);
	new_node -> next = NULL;
	return (new_node);
}

t_stack	*get_stack(size_t how_many_numbers, char **args, t_stack **stack)
{
	t_stack	*stack_head;
	t_stack	*new_node;
	t_stack	*last_node;
	size_t	i;

	i = -1;
	stack_head = NULL;
	while (++i < how_many_numbers)
	{
		new_node = get_new_node();
		if (i == 0)
		{
			stack_head = new_node;
			last_node = new_node;
			*stack = stack_head;
		}
		else
		{
			last_node -> next = new_node;
			last_node = last_node -> next;
		}
		new_node -> number = validate_and_convert(args[i], args, stack);
	}
	ft_get_indexes(stack_head, how_many_numbers - 1);
	return (stack_head);
}
