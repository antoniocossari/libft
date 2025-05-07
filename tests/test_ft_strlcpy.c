/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:24 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 20:29:21 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	dest1[10];
	char	dest2[10];
	size_t	ret_ft;
	size_t	ret_std;

	/* 1. Empty source, non-zero size */
	memset(dest1, 'X', sizeof(dest1));
	memset(dest2, 'X', sizeof(dest2));
	ret_ft  = ft_strlcpy(dest1, "", sizeof(dest1));
	ret_std = strlcpy(dest2, "", sizeof(dest2));
	assert(ret_ft == ret_std);
	assert(dest1[0] == '\0');
	assert(memcmp(dest1, dest2, sizeof(dest1)) == 0);

	/* 2. Source fits entirely */
	memset(dest1, 0, sizeof(dest1));
	memset(dest2, 0, sizeof(dest2));
	ret_ft  = ft_strlcpy(dest1, "Hello", sizeof(dest1));
	ret_std = strlcpy(dest2, "Hello", sizeof(dest2));
	assert(ret_ft == ret_std);
	assert(strcmp(dest1, "Hello") == 0);
	assert(strcmp(dest1, dest2) == 0);

	/* 3. Truncation when size too small */
	memset(dest1, 0, sizeof(dest1));
	memset(dest2, 0, sizeof(dest2));
	strcpy(dest1, "AAAA");  /* pre-fill to detect leftover */
	strcpy(dest2, "AAAA");
	ret_ft  = ft_strlcpy(dest1, "LongSource", 5);
	ret_std = strlcpy(dest2, "LongSource", 5);
	/* return value is length of src */
	assert(ret_ft == strlen("LongSource"));
	assert(ret_ft == ret_std);
	/* dest[0..3] == "Long", dest[4] == '\0' */
	assert(strncmp(dest1, "Long", 4) == 0);
	assert(dest1[4] == '\0');

	/* 4. Size is zero: nothing written, return src length */
	memset(dest1, 'Z', sizeof(dest1));
	ret_ft  = ft_strlcpy(dest1, "XYZ", 0);
	ret_std = strlcpy(dest2, "XYZ", 0);
	assert(ret_ft == strlen("XYZ"));
	assert(ret_ft == ret_std);
	/* dest1 unchanged */
	for (size_t i = 0; i < sizeof(dest1); i++)
		assert(dest1[i] == 'Z');

	return (0);
}
