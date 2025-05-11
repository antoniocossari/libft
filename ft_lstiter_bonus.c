/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:22:18 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 15:29:09 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_lstiter – iterate a list and apply a function to each element’s content
 * @lst: pointer to the first element of the list
 * @f:   function to apply to each node’s content
 *
 * For each node in the list, from first to last, calls f(node->content).
 * Does nothing if lst or f is NULL.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
