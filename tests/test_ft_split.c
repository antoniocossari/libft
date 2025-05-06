/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:14 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:23 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	free_split(char **arr)
{
	size_t	i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

int	main(void)
{
	char	**res;
	size_t	i;

	/* 1. Basic split on spaces */
	res = ft_split("hello world test", ' ');
	assert(res != NULL);
	assert(strcmp(res[0], "hello") == 0);
	assert(strcmp(res[1], "world") == 0);
	assert(strcmp(res[2], "test")  == 0);
	assert(res[3] == NULL);
	free_split(res);

	/* 2. Leading, trailing, and multiple delimiters */
	res = ft_split("  a  bc   d ", ' ');
	assert(res != NULL);
	assert(strcmp(res[0], "a")  == 0);
	assert(strcmp(res[1], "bc") == 0);
	assert(strcmp(res[2], "d")  == 0);
	assert(res[3] == NULL);
	free_split(res);

	/* 3. No delimiters: whole string returned */
	res = ft_split("nodelem", ',');
	assert(res != NULL);
	assert(strcmp(res[0], "nodelem") == 0);
	assert(res[1] == NULL);
	free_split(res);

	/* 4. Only delimiters: results in empty array */
	res = ft_split("::::", ':');
	assert(res != NULL);
	assert(res[0] == NULL);
	free_split(res);

	/* 5. Empty string input */
	res = ft_split("", 'x');
	assert(res != NULL);
	assert(res[0] == NULL);
	free_split(res);

	return (0);
}
