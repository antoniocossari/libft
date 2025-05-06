/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:23 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:03 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	dest1[10];
	char	dest2[10];
	size_t	ret_ft;
	size_t	ret_std;

	/* 1. Empty dest, src fits wholly */
	memset(dest1, 0, sizeof(dest1));
	memset(dest2, 0, sizeof(dest2));
	ret_ft  = ft_strlcat(dest1, "Hello", sizeof(dest1));
	ret_std = strlcat(dest2, "Hello", sizeof(dest2));
	assert(ret_ft == ret_std);
	assert(strcmp(dest1, dest2) == 0);

	/* 2. Non‐empty dest, src fits wholly */
	strcpy(dest1, "Hi");
	strcpy(dest2, "Hi");
	ret_ft  = ft_strlcat(dest1, "There", sizeof(dest1));
	ret_std = strlcat(dest2, "There", sizeof(dest2));
	assert(ret_ft == ret_std);
	assert(strcmp(dest1, dest2) == 0);

	/* 3. Buffer too small: truncation occurs */
	memset(dest1, 0, sizeof(dest1));
	memset(dest2, 0, sizeof(dest2));
	strcpy(dest1, "1234");
	strcpy(dest2, "1234");
	ret_ft  = ft_strlcat(dest1, "ABCDE", 7);
	ret_std = strlcat(dest2, "ABCDE", 7);
	assert(ret_ft == ret_std);               /* return = init_len + src_len */
	assert(strncmp(dest1, dest2, 7) == 0);   /* only up to size-1, null‑terminated */

	/* 4. Size is zero: nothing written */
	strcpy(dest1, "Data");
	strcpy(dest2, "Data");
	ret_ft  = ft_strlcat(dest1, "XYZ", 0);
	ret_std = strlcat(dest2, "XYZ", 0);
	assert(ret_ft == ret_std);
	assert(strcmp(dest1, "Data") == 0);

	/* 5. Initial dest length >= size: return = size + src_len, dest unchanged */
	strcpy(dest1, "LONGDEST");
	strcpy(dest2, "LONGDEST");
	ret_ft  = ft_strlcat(dest1, "123", 5);
	ret_std = strlcat(dest2, "123", 5);
	assert(ret_ft == ret_std);
	assert(strcmp(dest1, "LONGDEST") == 0);

	return (0);
}
