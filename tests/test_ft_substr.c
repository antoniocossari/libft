/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:35 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:25 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	*res;

	/* 1. Basic case: substring in the middle */
	res = ft_substr("Hello world", 6, 5);
	assert(res != NULL && strcmp(res, "world") == 0);
	free(res);

	/* 2. From start: offset 0 */
	res = ft_substr("Testing", 0, 4);
	assert(res != NULL && strcmp(res, "Test") == 0);
	free(res);

	/* 3. Length longer than remaining string */
	res = ft_substr("Sample", 3, 10);
	assert(res != NULL && strcmp(res, "ple") == 0);
	free(res);

	/* 4. Start beyond string length: should return empty string */
	res = ft_substr("abc", 5, 2);
	assert(res != NULL && strcmp(res, "") == 0);
	free(res);

	/* 5. Zero length: always empty string */
	res = ft_substr("xyz", 1, 0);
	assert(res != NULL && strcmp(res, "") == 0);
	free(res);

	return (0);
}
