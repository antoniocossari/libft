/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:27 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:46 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/* sample mapping: shift each character by its index */
static char	add_index(unsigned int i, char c)
{
	return (char)(c + i);
}

int	main(void)
{
	char	*res;
	char	*expected;

	/* 1. Empty string → should return empty string */
	res = ft_strmapi("", add_index);
	assert(res != NULL && strcmp(res, "") == 0);
	free(res);

	/* 2. Simple mapping */
	/* "abcd" → "a"->'a'+0, "b"->'b'+1, ... = "ac\'f" */
	expected = strdup("acfh");
	res = ft_strmapi("abcd", add_index);
	assert(res != NULL && strcmp(res, expected) == 0);
	free(res);
	free(expected);

	/* 3. Mixed characters */
	expected = strdup("A`eg");
	/* 'A'+0 = 'A'; 'b'+1 = 'c'; 'c'+2 = 'e'; 'd'+3 = 'g' */
	res = ft_strmapi("Abcd", add_index);
	assert(res != NULL && strcmp(res, expected) == 0);
	free(res);
	free(expected);

	/* 4. Longer string */
	const char *src = "Hello!";
	size_t	len = strlen(src);
	expected = malloc(len + 1);
	for (unsigned int i = 0; i < len; i++)
		expected[i] = (char)(src[i] + i);
	expected[len] = '\0';
	res = ft_strmapi(src, add_index);
	assert(res != NULL && strcmp(res, expected) == 0);
	free(res);
	free(expected);

	return (0);
}
