/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:01 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 18:10:03 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	del_count;

static void	del_fct(void *content)
{
	(void)content;
	del_count++;
}

int	main(void)
{
	t_list	*list;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	/* 1. Clearing a NULL list does nothing */
	list = NULL;
	del_count = 0;
	ft_lstclear(&list, del_fct);
	assert(list == NULL);
	assert(del_count == 0);

	/* 2. Clearing a multi-element list frees all nodes */
	n1 = ft_lstnew("one");
	n2 = ft_lstnew("two");
	n3 = ft_lstnew("three");
	n1->next = n2;
	n2->next = n3;
	list = n1;
	del_count = 0;
	ft_lstclear(&list, del_fct);
	assert(list == NULL);
	assert(del_count == 3);

	/* 3. Passing NULL del causes no action */
	n1 = ft_lstnew("A");
	n2 = ft_lstnew("B");
	n1->next = n2;
	list = n1;
	del_count = 0;
	ft_lstclear(&list, NULL);
	assert(list == n1);
	assert(del_count == 0);
	free(n2);
	free(n1);

	return (0);
}
