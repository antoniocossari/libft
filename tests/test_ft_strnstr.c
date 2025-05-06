/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:30 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:38 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	const char	*hay = "hello world";
	const char	*res_ft;
	const char	*res_std;

	/* 1. Empty needle: should return haystack */
	res_ft  = ft_strnstr(hay, "", 5);
	res_std = strnstr(hay, "", 5);
	assert(res_ft == res_std);

	/* 2. Basic find within limit */
	res_ft  = ft_strnstr(hay, "world", 11);
	res_std = strnstr(hay, "world", 11);
	assert(res_ft == res_std);

	/* 3. Needle not in haystack */
	res_ft  = ft_strnstr(hay, "abc", 11);
	res_std = strnstr(hay, "abc", 11);
	assert(res_ft == res_std && res_ft == NULL);

	/* 4. Limit too small: needle straddles boundary */
	res_ft  = ft_strnstr(hay, "world", 10);
	res_std = strnstr(hay, "world", 10);
	assert(res_ft == res_std && res_ft == NULL);

	/* 5. Find at very end (including \\0) */
	res_ft  = ft_strnstr(hay, "d", 12);
	res_std = strnstr(hay, "d", 12);
	assert(res_ft == res_std);

	/* 6. Zero length search: should return NULL unless needle empty */
	res_ft  = ft_strnstr(hay, "h", 0);
	res_std = strnstr(hay, "h", 0);
	assert(res_ft == res_std && res_ft == NULL);

	/* 7. Needle longer than haystack within n */
	res_ft  = ft_strnstr("short", "longneedle", 20);
	res_std = strnstr("short", "longneedle", 20);
	assert(res_ft == res_std && res_ft == NULL);

	return (0);
}
