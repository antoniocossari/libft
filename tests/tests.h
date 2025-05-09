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

/*
 * Strip out any existing strlcat/strlcpy macros or prototypes
 * so our inline stubs won’t collide with the system’s.
 */
# undef strlcat
# undef strlcpy

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"

/*
 * Inline stub for strlcat:
 *   Append src to the end of dst of total size dstsize,
 *   NUL-terminating if there is room.
 *   Returns initial dst length + src length.
 * Implementation adapted from the official BSD/libbsd reference.
 */
extern inline size_t
strlcat(char *dst, const char *src, size_t dstsize)
{
    char   *odst = dst;
    size_t  n    = dstsize;
    size_t  dlen;

    while (n-- != 0 && *dst != '\0')
        dst++;
    dlen = dst - odst;
    n    = dstsize - dlen;

    if (n == 0)
        return (dlen + strlen(src));

    {
        size_t copy_n = (n - 1);
        size_t srclen = strlen(src);

        if (copy_n > srclen)
            copy_n = srclen;
        memcpy(odst + dlen, src, copy_n);
        odst[dlen + copy_n] = '\0';
    }
    return (dlen + strlen(src));
}

/*
 * Inline stub for strlcpy:
 *   Copy up to dstsize-1 bytes from src into dst,
 *   NUL-terminating if dstsize > 0.
 *   Returns total length of src.
 */
extern inline size_t
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

/*
 * Inline stub for strnstr:
 *   Locate the first occurrence of needle in haystack,
 *   where no more than len bytes are searched.
 * Returns pointer to match or NULL.
 */
extern inline char *
strnstr(const char *haystack, const char *needle, size_t len)
{
    const char *h;
    size_t      needlelen;  /* <- qui non c’è nessuna 's' di troppo */

    if (*needle == '\0')
        return (char *)haystack;
    needlelen = strlen(needle);

    for (h = haystack; (h = strchr(h, *needle)) != NULL; h++)
    {
        if ((size_t)(h - haystack) + needlelen > len)
            return NULL;
        if (strncmp(h, needle, needlelen) == 0)
            return (char *)h;
    }
    return NULL;
}

/* Helper: libera tutti i nodi e il loro content */
void free_list(t_list *lst)
{
    t_list *tmp;
    while (lst)
    {
        tmp = lst->next;
        free(lst->content);  /* libera la stringa strdupata */
        free(lst);
        lst = tmp;
    }
}

#endif /* TESTS_H */
