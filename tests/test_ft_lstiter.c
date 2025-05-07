/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:05 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 18:10:19 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	increment(void *content)
{
	(*(int *)content)++;
}

int	main(void)
{
	/* Function: ft_lstiter – apply a function to each element’s content */

	/* 1. NULL list does nothing */
	int	x = 0;
	ft_lstiter(NULL, increment);
	assert(x == 0);

	/* 2. NULL function pointer does nothing */
	int	a = 10;
	t_list	*n1 = ft_lstnew(&a);
	ft_lstiter(n1, NULL);
	assert(a == 10);

	/* 3. Single-node list is modified once */
	ft_lstiter(n1, increment);
	assert(a == 11);

	/* 4. Multi-node list: each element is modified */
	int	b = 20;
	int	c = 30;
	ft_lstadd_back(&n1, ft_lstnew(&b));
	ft_lstadd_back(&n1, ft_lstnew(&c));
	ft_lstiter(n1, increment);
	assert(a == 12);
	assert(b == 21);
	assert(c == 31);

	/* 5. List structure remains intact */
	assert(n1->next->next->next == NULL);

	return (0);
}
