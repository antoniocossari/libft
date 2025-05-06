/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:40 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:25 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	buf1[5] = "abcd";
	char	buf2[5] = "zzzzz";
	char	buf3[1] = { 'x' };

	/* 1. Zero 0 bytes: buffer stays the same */
	ft_bzero(buf1, 0);
	assert(memcmp(buf1, "abcd", 5) == 0);

	/* 2. Zero first 3 bytes */
	memcpy(buf2, "abcde", 5);       /* reset to known data */
	ft_bzero(buf2, 3);
	assert(buf2[0] == '\0');
	assert(buf2[1] == '\0');
	assert(buf2[2] == '\0');
	/* remaining bytes untouched */
	assert(buf2[3] == 'd');
	assert(buf2[4] == 'e');

	/* 3. Zero entire buffer */
	memcpy(buf1, "1234", 5);
	ft_bzero(buf1, sizeof(buf1));
	for (size_t i = 0; i < sizeof(buf1); i++)
		assert(buf1[i] == '\0');

	/* 4. Zero on minimal buffer */
	ft_bzero(buf3, 1);
	assert(buf3[0] == '\0');

	return (0);
}