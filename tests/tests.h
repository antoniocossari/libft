/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:56:25 by acossari          #+#    #+#             */
/*   Updated: 2025/05/09 11:49:14 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <assert.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
 * Undefine any existing declarations or macros for strlcat/strlcpy
 * so that our static inline versions won’t conflict with the
 * ones in <string.h> (glibc exports non-static prototypes).
 */
# undef strlcat
# undef strlcpy

/* Now include string.h to get strlen, memcpy, strchr, strncmp, etc. */
# include <string.h>
# include "libft.h"

/*
 * Inline implementation of strlcat:
 * Append src to the end of dst, for a total buffer size dstsize.
 * Always NUL-terminates (if there’s room). Returns the initial
 * length of dst plus the length of src.
 *
 * Official reference: OpenBSD strlcat(3) / FreeBSD strlcat(3)
 */
static inline size_t
strlcat(char *dst, const char *src, size_t dstsize)
{
	char   *odst = dst;
	size_t  n    = dstsize;
	size_t  dlen;

	/* Find end of dst and adjust bytes left but don’t go past dstsize */
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dstsize - dlen;

	if (n == 0)
		return (dlen + strlen(src));

	/* Copy as many bytes as will fit, leaving room for NUL */
	{
		size_t copy_n = dstsize - dlen - 1;
		size_t slen   = strlen(src);

		if (copy_n > slen)
			copy_n = slen;
		memcpy(odst + dlen, src, copy_n);
		odst[dlen + copy_n] = '\0';
	}

	return (dlen + strlen(src));
}

/*
 * Inline implementation of strlcpy:
 * Copy up to dstsize-1 bytes from src to dst, NUL-terminating dst.
 * Returns the total length of src; if that’s >= dstsize, truncation occurred.
 *
 * Official reference: OpenBSD strlcpy(3) / FreeBSD strlcpy(3)
 */
static inline size_t
strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t slen = strlen(src);
	size_t i;

	if (dstsize != 0)
	{
		for (i = 0; i + 1 < dstsize && src[i]; i++)
			dst[i] = src[i];
		dst[i] = '\0';
	}

	return (slen);
}

/*
 * Inline strnstr:
 * Locate the first occurrence of needle in haystack, where not more
 * than len characters are searched. Characters after a ‘\0’ are not searched.
 */
static inline char *
strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t nlen;

	if (*needle == '\0')
		return (char *)haystack;
	nlen = strlen(needle);

	for (; *haystack; haystack++)
	{
		if (haystack[0] == needle[0] &&
			(size_t)(haystack - (const char *)haystack) + nlen <= len &&
			strncmp(haystack, needle, nlen) == 0)
			return (char *)haystack;
	}
	return NULL;
}

#endif /* TESTS_H */
