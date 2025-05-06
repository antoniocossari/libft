/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:19 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:11 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	to_upper_even(unsigned int i, char *c)
{
	if ((i % 2) == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - ('a' - 'A');
	else if ((i % 2) == 1 && *c >= 'A' && *c <= 'Z')
		*c = *c + ('a' - 'A');
}

int	main(void)
{
	char	*str;
	char	*expected;

	/* 1. Empty string: nothing to do */
	str = strdup("");
	assert(str != NULL);
	ft_striteri(str, to_upper_even);
	assert(strcmp(str, "") == 0);
	free(str);

	/* 2. All lowercase → uppercase on even indices */
	str = strdup("abcdefg");
	assert(str != NULL);
	expected = strdup("AbCdEfG");
	ft_striteri(str, to_upper_even);
	assert(strcmp(str, expected) == 0);
	free(str);
	free(expected);

	/* 3. Mixed case → alternating */
	str = strdup("HeLlOWoRlD");
	assert(str != NULL);
	expected = strdup("HELLoWoRLd");
	ft_striteri(str, to_upper_even);
	assert(strcmp(str, expected) == 0);
	free(str);
	free(expected);

	/* 4. Non‐alphabetic chars remain unchanged */
	str = strdup("123-456-789");
	assert(str != NULL);
	expected = strdup("123-456-789");
	ft_striteri(str, to_upper_even);
	assert(strcmp(str, expected) == 0);
	free(str);
	free(expected);

	/* 5. Null pointer should do nothing (undefined behavior allowed by libft?) */
	/* We skip ft_striteri(NULL, func) as behavior is undefined in subject */

	return (0);
}
