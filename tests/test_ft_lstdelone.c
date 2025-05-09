/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:03 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 18:09:55 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/*
 * test_del – helper that frees the content and sets a flag
 */
static int deleted_flag;
static void test_del(void *content)
{
	free(content);
	deleted_flag = 1;
}

int main(void)
{
	t_list *n1;
	t_list *n2;
	char   *data;

	/* 1. Passing NULL lst should do nothing */
	deleted_flag = 0;
	ft_lstdelone(NULL, test_del);
	assert(deleted_flag == 0);

	/* 2. Passing NULL del should do nothing */
	n1 = ft_lstnew(strdup("data"));
	deleted_flag = 0;
	ft_lstdelone(n1, NULL);
	assert(deleted_flag == 0);
	/* Manually free since del was NULL */
	free(n1->content);
	free(n1);

	/* 3. del is called on the content and node is freed */
	data = malloc(1);
	n2   = ft_lstnew(data);
	deleted_flag = 0;
	ft_lstdelone(n2, test_del);
	assert(deleted_flag == 1);

	return 0;
}
