/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:56:25 by acossari          #+#    #+#             */
/*   Updated: 2025/05/08 14:42:01 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <assert.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# undef strlcat
static inline size_t
strlcat(char *dst, const char *src, size_t dstsize)
{
	char *odst = dst;
	size_t n = dstsize;
	size_t dlen;

	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + strlen(src));
	{
		size_t copy_n = dstsize - dlen - 1;
		size_t srclen = strlen(src);
		if (copy_n > srclen)
			copy_n = srclen;
		memcpy(odst + dlen, src, copy_n);
		odst[dlen + copy_n] = '\0';
	}
	return (dlen + strlen(src));
}

# undef strlcpy
static inline size_t
strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srclen = strlen(src);
	size_t i;

	if (dstsize != 0)
	{
		for (i = 0; i + 1 < dstsize && src[i]; i++)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (srclen);
}

# undef strnstr
static inline char *
strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *h;
	size_t lneedle;

	if (*needle == '\0')
		return (char *)haystack;
	lneedle = strlen(needle);
	for (h = haystack; (h = strchr(h, *needle)) != NULL; h++) {
		if ((size_t)(h - haystack) + lneedle > len)
			return NULL;
		if (strncmp(h, needle, lneedle) == 0)
			return (char *)h;
	}
	return NULL;
}

#endif /* TESTS_H */
