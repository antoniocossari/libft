/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:22:11 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 15:26:31 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstadd_back – add the node ’new’ at the end of the list
 * @lst:  address of the pointer to the first element of the list
 * @new:  node to add at the end
 *
 * If the list is empty, new becomes the first node.
 * Otherwise, find the last node and set its next to new.
 * Always sets new->next = NULL to avoid dangling pointers.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
