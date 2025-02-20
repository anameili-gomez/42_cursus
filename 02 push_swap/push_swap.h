/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:32 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 19:22:27 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef struct s_stack
{
	int				number;
	size_t			index;
	struct s_stack	*next;
}			t_stack;

int		double_number(int n, t_stack **stack);
size_t	ft_strdigit(char *s);
int		other_character(char *str);
int		validate_and_convert(char *number, char **args, t_stack **stack);
int		already_sorted(t_stack *stack);

void	free_arguments(char **args);
void	free_stack(t_stack **stack);
void	exit_error(char **args, t_stack **stack);
void	exit_wo_error(t_stack **stack_a, t_stack **stack_b, char **args);

long	ft_atol(const char *str);

char	*copy_args(char *av);
char	**get_args(int ac, char **av);
size_t	ft_get_numbers(char **args);
t_stack	*get_new_node(void);
t_stack	*get_stack(size_t how_many_numbers, char **args, t_stack **stack);

void	ft_reset_index(t_stack *stack);
t_stack	*ft_find_min(t_stack *stack);
void	ft_get_indexes(t_stack *stack, size_t last_index);

void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_to, t_stack **stack_from);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);;
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b, int bit_size, int j);
void	main_sort(t_stack **stack_a, t_stack **stack_b, size_t size);

int		top_order(t_stack *stack);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b, size_t size);

size_t	ft_stacksize(t_stack *lst);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

int		ft_find_position(t_stack *stack, int i);
void	ft_pushing(t_stack **stack_a, t_stack **stack_b, int size, int number);
int		ft_find_cost(t_stack *stack, int n, size_t size);
void	main_sort(t_stack **stack_a, t_stack **stack_b, size_t size);

#endif
