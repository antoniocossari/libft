/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:22:23 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 15:30:16 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_lstnew – create a new list node
 * @content: pointer to the data to be stored in the node
 *
 * Allocates (with malloc) and returns a new node. 
 * The member ‘content’ is initialized with the value of ‘content’.
 * The member ‘next’ is initialized to NULL.
 * Returns the new node, or NULL if the allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}