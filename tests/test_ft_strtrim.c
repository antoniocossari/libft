/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:34 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:30 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	*res;

	/* 1. Trim spaces */
	res = ft_strtrim("  hello world  ", " ");
	assert(res != NULL && strcmp(res, "hello world") == 0);
	free(res);

	/* 2. Trim multiple characters */
	res = ft_strtrim("xx--trim--xx", "x-");
	assert(res != NULL && strcmp(res, "trim") == 0);
	free(res);

	/* 3. No characters to trim (set empty) */
	res = ft_strtrim("keep", "");
	assert(res != NULL && strcmp(res, "keep") == 0);
	free(res);

	/* 4. Trim entire string → should return empty string */
	res = ft_strtrim("aaaaa", "a");
	assert(res != NULL && strcmp(res, "") == 0);
	free(res);

	/* 5. Empty input string */
	res = ft_strtrim("", " ");
	assert(res != NULL && strcmp(res, "") == 0);
	free(res);

	return (0);
}
