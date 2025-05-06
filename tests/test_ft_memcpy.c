/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:59 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:47 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	src1[] = "Hello, world!";
	char	dst1[20];
	char	dst2[20];
	unsigned char	buf1[] = {1, 2, 3, 4, 5};
	unsigned char	buf2[5];
	size_t	i;

	/* 1. Copy zero bytes: dst unchanged */
	memset(dst1, 'A', sizeof(dst1));
	memcpy(dst2, dst1, sizeof(dst1));
	ft_memcpy(dst1, src1, 0);
	assert(memcmp(dst1, dst2, sizeof(dst1)) == 0);

	/* 2. Copy full string including '\\0' */
	ft_memcpy(dst1, src1, strlen(src1) + 1);
	assert(strcmp(dst1, src1) == 0);

	/* 3. Copy part of string */
	memset(dst1, 0, sizeof(dst1));
	ft_memcpy(dst1, src1 + 7, 5);
	assert(memcmp(dst1, "world", 5) == 0);

	/* 4. Copy binary data */
	ft_memcpy(buf2, buf1, sizeof(buf1));
	for (i = 0; i < sizeof(buf1); i++)
		assert(buf2[i] == buf1[i]);

	/* 5. Null pointers with zero length (allowed) */
	ft_memcpy(NULL, NULL, 0);

	return (0);
}
