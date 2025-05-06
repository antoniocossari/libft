/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:26 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:51 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	long_str[100];
	size_t	i;

	/* 1. Empty string */
	assert(ft_strlen("") == 0);

	/* 2. Short literals */
	assert(ft_strlen("42") == 2);
	assert(ft_strlen("libft") == 5);

	/* 3. Longer string */
	assert(ft_strlen("Hello, world!") == 13);

	/* 4. Embedded null stops count */
	assert(ft_strlen("with\0null") == 4);

	/* 5. Compare against standard strlen */
	assert(ft_strlen("Compare me!") == strlen("Compare me!"));

	/* 6. Large buffer of ’a’s */
	for (i = 0; i < 99; i++)
		long_str[i] = 'a';
	long_str[99] = '\0';
	assert(ft_strlen(long_str) == 99);

	return (0);
}
