/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:58 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:51 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	s1[] = "abcdef";
	char	s2[] = "abcdef";
	char	s3[] = "abcdez";
	char	s4[] = "abcda";
	char	b1[] = {1, 2, 3, 4, 5};
	char	b2[] = {1, 2, 0, 4, 5};

	/* 1. Zero length comparison: always equal */
	ft_memcmp(s1, s3, 0);
	assert(ft_memcmp(s1, s3, 0) == 0);

	/* 2. Identical buffers */
	assert(ft_memcmp(s1, s2, strlen(s1) + 1) == 0);

	/* 3. Difference at first mismatch */
	/* 'f' (102) < 'z' (122) → negative */
	assert(ft_memcmp(s1, s3, 6) < 0);
	/* reverse: positive */
	assert(ft_memcmp(s3, s1, 6) > 0);

	/* 4. s1 vs shorter s4: 'f' (102) > '\0' (0) → positive */
	assert(ft_memcmp(s1, s4, 6) > 0);

	/* 5. Partial compare, identical prefix */
	assert(ft_memcmp(s1, s3, 3) == 0);

	/* 6. Binary data comparison */
	assert(ft_memcmp(b1, b2, 2) == 0);
	/* mismatch at third byte: 3 > 0 → positive */
	assert(ft_memcmp(b1, b2, 3) > 0);

	return (0);
}
