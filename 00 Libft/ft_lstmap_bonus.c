/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:34:13 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 12:56:18 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstcreatenode(void *(*f)(void *), void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = f(content);
	new_node->next = NULL;
	return (new_node);
}

static void	ft_lstadd(t_list **new_lst, t_list **temp, t_list *new_node)
{
	if (*new_lst == NULL)
	{
		*new_lst = new_node;
		*temp = *new_lst;
	}
	else
	{
		(*temp)->next = new_node;
		*temp = (*temp)->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*temp;

	new_lst = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstcreatenode(f, lst->content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd(&new_lst, &temp, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
