/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:15 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 17:51:04 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/*
 * Test for ft_lstsize – returns the number of nodes in a list
 */
int main(void)
{
	t_list *list = NULL;

	/* 1. Empty list should have size 0 */
	assert(ft_lstsize(list) == 0);

	/* 2. Single-node list should have size 1 */
	char *s1 = strdup("one");
	t_list *n1 = ft_lstnew(s1);
	list = n1;
	assert(ft_lstsize(list) == 1);

	/* 3. Two-node list should have size 2 */
	char *s2 = strdup("two");
	t_list *n2 = ft_lstnew(s2);
	ft_lstadd_back(&list, n2);
	assert(ft_lstsize(list) == 2);

	/* 4. Three-node list should have size 3 */
	char *s3 = strdup("three");
	t_list *n3 = ft_lstnew(s3);
	ft_lstadd_back(&list, n3);
	assert(ft_lstsize(list) == 3);

	/* 5. Original links are intact */
	assert(list->next == n2);
	assert(list->next->next == n3);

	/* Free all nodes and their content to avoid memory leaks */
	free_list(list);

	return 0;
}
