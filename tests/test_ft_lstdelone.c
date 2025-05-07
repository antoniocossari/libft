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

static int	deleted_flag;

static void	test_del(void *content)
{
	(void)content;
	deleted_flag = 1;
}

int	main(void)
{
	/* 1. Passing NULL lst does nothing */
	deleted_flag = 0;
	ft_lstdelone(NULL, test_del);
	assert(deleted_flag == 0);

	/* 2. Passing NULL del does nothing */
	t_list	*n1 = ft_lstnew("data");
	deleted_flag = 0;
	ft_lstdelone(n1, NULL);
	assert(deleted_flag == 0);
	free(n1);

	/* 3. del is called on the content */
	char	*data = malloc(1);
	t_list	*n2 = ft_lstnew(data);
	deleted_flag = 0;
	ft_lstdelone(n2, test_del);
	assert(deleted_flag == 1);

	return (0);
}
