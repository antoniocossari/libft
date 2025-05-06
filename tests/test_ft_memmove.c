/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:01 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:41 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	buf1[20];
	char	buf2[20];

	/* 1. Non-overlapping copy (like memcpy) */
	strcpy(buf1, "Hello, world!");
	ft_memmove(buf2, buf1, strlen(buf1) + 1);
	assert(strcmp(buf2, "Hello, world!") == 0);

	/* 2. Overlapping: dest < src (forward overlap) */
	/* buf1 = "1234567890"; move "345678" to start */
	strcpy(buf1, "1234567890");
	ft_memmove(buf1, buf1 + 2, 6);
	assert(strncmp(buf1, "345678", 6) == 0);

	/* 3. Overlapping: dest > src (backward overlap) */
	/* buf1 = "abcdefghij"; move "abcd" forward by 2 */
	strcpy(buf1, "abcdefghij");
	ft_memmove(buf1 + 2, buf1, 4);
	assert(strncmp(buf1 + 2, "abcd", 4) == 0);

	/* 4. Zero length does nothing */
	strcpy(buf1, "TestString");
	strcpy(buf2, "Unchanged");
	ft_memmove(buf1, buf2, 0);
	assert(strcmp(buf1, "TestString") == 0);

	/* 5. Null pointers with zero length (allowed) */
	ft_memmove(NULL, NULL, 0);

	return (0);
}
