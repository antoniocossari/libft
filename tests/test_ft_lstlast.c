/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:07 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 18:09:49 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* 1. Empty list should return NULL */
	t_list	*list = NULL;
	assert(ft_lstlast(list) == NULL);

	/* 2. Single-element list returns that element */
	t_list	*n1 = ft_lstnew("one");
	list = n1;
	assert(ft_lstlast(list) == n1);

	/* 3. Two-element list returns the second node */
	t_list	*n2 = ft_lstnew("two");
	ft_lstadd_back(&list, n2);
	assert(ft_lstlast(list) == n2);

	/* 4. Adding to front doesn't change last */
	t_list	*n0 = ft_lstnew("zero");
	ft_lstadd_front(&list, n0);
	assert(ft_lstlast(list) == n2);

	/* 5. Verify chain integrity */
	assert(n0->next == n1);
	assert(n1->next == n2);

	return (0);
}
