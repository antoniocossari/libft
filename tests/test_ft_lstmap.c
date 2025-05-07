/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:10 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 18:17:53 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	*double_int(void *content)
{
	int	*src = content;
	int	*dst = malloc(sizeof(int));

	if (!dst)
		return (NULL);
	*dst = (*src) * 2;
	return (dst);
}

static void	del_int(void *content)
{
	free(content);
}

int	main(void)
{
	/* 1. Mapping a NULL list returns NULL */
	assert(ft_lstmap(NULL, double_int, del_int) == NULL);

	/* 2. Map single‑node list */
	int		*x = malloc(sizeof(int));
	*x = 5;
	t_list	*n1 = ft_lstnew(x);
	t_list	*mapped1 = ft_lstmap(n1, double_int, del_int);
	assert(mapped1);
	assert(*(int *)mapped1->content == 10);
	assert(mapped1->next == NULL);
	ft_lstclear(&mapped1, del_int);
	ft_lstclear(&n1, del_int);

	/* 3. Map multi‑node list */
	int		*pb = malloc(sizeof(int));
	int		*pc = malloc(sizeof(int));
	int		*pd = malloc(sizeof(int));
	*pb = 1; *pc = 2; *pd = 3;

	t_list	*l1 = ft_lstnew(pb);
	ft_lstadd_back(&l1, ft_lstnew(pc));
	ft_lstadd_back(&l1, ft_lstnew(pd));

	t_list	*mapped = ft_lstmap(l1, double_int, del_int);

	/* 3.1 New list has same size */
	assert(ft_lstsize(mapped) == 3);

	/* 3.2 Contents are doubled and in correct order */
	assert(*(int *)mapped->content == 2);
	assert(*(int *)mapped->next->content == 4);
	assert(*(int *)mapped->next->next->content == 6);

	/* 3.3 Original list remains unchanged */
	assert(*(int *)l1->content == 1);
	assert(*(int *)l1->next->content == 2);
	assert(*(int *)l1->next->next->content == 3);

	/* Cleanup */
	ft_lstclear(&mapped, del_int);
	ft_lstclear(&l1, del_int);

	return (0);
}
