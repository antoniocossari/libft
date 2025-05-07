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
 * ft_lstiter – iterate over a list and apply a function to each element’s content
 * @lst: pointer to the first element of the list
 * @f:   function to apply to the content of each node
 *
 * Applies the function f to the content of each node in the list,
 * in order from the first to the last. Does nothing if lst or f is NULL.
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
