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

int	main(void)
{
	/* 1. Empty list should have size 0 */
	t_list	*list = NULL;
	assert(ft_lstsize(list) == 0);

	/* 2. Single node list should have size 1 */
	t_list	*n1 = ft_lstnew("one");
	list = n1;
	assert(ft_lstsize(list) == 1);

	/* 3. Two-node list should have size 2 */
	t_list	*n2 = ft_lstnew("two");
	ft_lstadd_back(&list, n2);
	assert(ft_lstsize(list) == 2);

	/* 4. Three-node list should have size 3 */
	t_list	*n3 = ft_lstnew("three");
	ft_lstadd_back(&list, n3);
	assert(ft_lstsize(list) == 3);

	/* 5. Original links are intact */
	assert(list->next == n2);
	assert(list->next->next == n3);

	return (0);
}
