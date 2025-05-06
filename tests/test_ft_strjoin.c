/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:21 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:08 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	*res;
	char	*res2;

	/* 1. Join two non-empty strings */
	res = ft_strjoin("Hello, ", "World!");
	assert(res != NULL && strcmp(res, "Hello, World!") == 0);
	free(res);

	/* 2. First string empty */
	res = ft_strjoin("", "Test");
	assert(res != NULL && strcmp(res, "Test") == 0);
	free(res);

	/* 3. Second string empty */
	res = ft_strjoin("Test", "");
	assert(res != NULL && strcmp(res, "Test") == 0);
	free(res);

	/* 4. Both empty */
	res = ft_strjoin("", "");
	assert(res != NULL && strcmp(res, "") == 0);
	free(res);

	/* 5. NULL pointers (undefined by subject, skip actual call) */
	/* Some implementations may crash; subject does not require handling NULL. */

	/* 6. Complex strings */
	res = ft_strjoin("Line\n", "Break\n");
	assert(res != NULL && strcmp(res, "Line\nBreak\n") == 0);
	free(res);

	/* 7. Memory independence */
	res = ft_strjoin("Foo", "Bar");
	res2 = ft_strjoin("Foo", "Bar");
	assert(res != res2);          /* different allocations */
	assert(strcmp(res, res2) == 0);
	free(res);
	free(res2);

	return (0);
}
