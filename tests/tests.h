/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:56:25 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 20:41:20 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

/* Assertions for runtime checks (prints file:line if false, then aborts) */
# include <assert.h>

/* String functions used in comparisons: strcmp, strncmp, memcmp */
# include <string.h>

/* malloc/free, abort(), strdup (if needed) */
# include <stdlib.h>

/* POSIX I/O for pipe(), read(), write() */
# include <unistd.h>

/* INT_MAX, INT_MIN for boundary tests */
# include <limits.h>

/* Include your library’s public API */
# include "libft.h"

/*
 * FreeBSD/OpenBSD strlcat implementation
 * Appends src to string dst of full size dstsize.
 * Always NUL-terminates (unless dstsize <= strlen(dst)).
 * Returns strlen(src) + MIN(dstsize, strlen(initial dst)).
 */
static inline size_t
strlcat(char *dst, const char *src, size_t dstsize)
{
	const char *odst = dst;
	const char *osrc = src;
	size_t n = dstsize;
	size_t dlen;

	/* Find end of dst and adjust bytes left but don't go past end. */
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dstsize - dlen;

	if (n == 0)
		return (dlen + strlen(src));

	/* Copy as many bytes as will fit. */
	while (*src != '\0') {
		if (n != 1) {
			*dst++ = *src;
			n--;
		}
		src++;
	}

	*dst = '\0';

	return (dlen + (src - osrc));
}

/*
 * FreeBSD/OpenBSD strlcpy implementation
 * Copies up to dstsize-1 bytes from src to dst, NUL-terminating.
 * Returns strlen(src).
 */
static inline size_t
strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char *osrc = src;
	size_t n = dstsize;

	if (n != 0) {
		while (--n != 0) {
			if ((*dst++ = *src++) == '\0')
				break;
		}
	}

	if (n == 0) {
		if (dstsize != 0)
			*dst = '\0';  /* NUL-terminate */
		while (*src++)
			;
	}

	return (src - osrc - 1);
}

/*
 * FreeBSD strnstr — locate first occurrence of needle in haystack
 * within the first len characters. Always NUL-terminates.
 * Source: FreeBSD/OpenBSD lib/libc/string/strnstr.c
 */
static inline char *
strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *h;
	size_t    lneedle;

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
