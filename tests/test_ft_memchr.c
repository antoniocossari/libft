/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:56 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:58 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	s[] = "Hello, memchr!";

	/* 1. Find a character in the middle */
	assert(ft_memchr(s, 'm', strlen(s)) == memchr(s, 'm', strlen(s)));

	/* 2. Character not found should return NULL */
	assert(ft_memchr(s, 'z', strlen(s)) == NULL);

	/* 3. Find at the very beginning */
	assert(ft_memchr(s, 'H', strlen(s)) == memchr(s, 'H', strlen(s)));

	/* 4. Zero length search returns NULL */
	assert(ft_memchr(s, 'H', 0) == NULL);

	/* 5. Searching for '\\0' finds the terminator */
	assert(ft_memchr(s, '\0', strlen(s) + 1) == memchr(s, '\0', strlen(s) + 1));

	return (0);
}
