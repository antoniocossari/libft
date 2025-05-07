/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:33:54 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 18:10:10 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	t_list	*list = NULL;
	t_list	*n1 = ft_lstnew("first");
	t_list	*n2 = ft_lstnew("second");
	t_list	*n3 = ft_lstnew("third");

	/* 1. Adding to empty list sets head to new node */
	ft_lstadd_back(&list, n1);
	assert(list == n1);
	assert(list->next == NULL);

	/* 2. Adding second node links it as next of head */
	ft_lstadd_back(&list, n2);
	assert(list->next == n2);
	assert(n2->next == NULL);

	/* 3. Adding third node links correctly at end */
	ft_lstadd_back(&list, n3);
	assert(list->next->next == n3);
	assert(n3->next == NULL);

	/* 4. List size increases accordingly */
	assert(ft_lstsize(list) == 3);

	/* 5. Passing NULL new node does not change list */
	ft_lstadd_back(&list, NULL);
	assert(ft_lstsize(list) == 3);

	return (0);
}
