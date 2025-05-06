/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:03 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 20:08:09 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char			buf1[10];
	char			buf2[10];
	unsigned char	bin2[5];
	size_t			i;

	/* 1. Zero length: no change */
	strcpy(buf1, "123456789");
	strcpy(buf2, "123456789");
	ft_memset(buf1, 'X', 0);
	assert(strcmp(buf1, buf2) == 0);

	/* 2. Fill full buffer including '\0' */
	ft_memset(buf1, 'A', sizeof(buf1));
	for (i = 0; i < sizeof(buf1); i++)
		assert(buf1[i] == 'A');

	/* 3. Partial fill */
	strcpy(buf1, "abcdefghi");
	ft_memset(buf1 + 2, 'Z', 4);
	/* buf1 should now be "abZZZZghi" */
	assert(buf1[0] == 'a' && buf1[1] == 'b');
	for (i = 2; i < 6; i++)
		assert(buf1[i] == 'Z');
	assert(buf1[6] == 'g');

	/* 4. Binary data */
	ft_memset(bin2, 0xFF, sizeof(bin2));
	for (i = 0; i < sizeof(bin2); i++)
		assert(bin2[i] == 0xFF);

	/* 5. Null pointer with zero length is allowed */
	ft_memset(NULL, 0, 0);

	return (0);
}
