/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:17 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:16 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	*original;
	char	*copy;

	/* 1. Simple string */
	original = "Hello, Libft!";
	copy = ft_strdup(original);
	assert(copy != NULL);
	assert(strcmp(copy, original) == 0);
	free(copy);

	/* 2. Empty string */
	original = "";
	copy = ft_strdup(original);
	assert(copy != NULL);
	assert(strcmp(copy, original) == 0);
	free(copy);

	/* 3. Independent allocation */
	original = "Test";
	copy = ft_strdup(original);
	assert(copy != original);
	assert(&copy[0] != &original[0]);
	free(copy);

	/* 4. Longer string */
	original = "This is a longer test string with multiple words.";
	copy = ft_strdup(original);
	assert(copy != NULL);
	assert(strcmp(copy, original) == 0);
	free(copy);

	return (0);
}
