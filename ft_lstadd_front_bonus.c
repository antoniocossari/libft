/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:22:14 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 15:25:50 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_lstadd_front – add the node ’new’ at the beginning of the list
 * @lst: address of the pointer to the first element of the list
 * @new: node to add at the beginning
 *
 * Places new->next pointing to the former head, 
 * then updates *lst to be the new node.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
