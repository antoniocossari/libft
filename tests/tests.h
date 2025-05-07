/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:56:25 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 11:55:43 by acossari         ###   ########.fr       */
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

/* On macOS, these BSD functions already exist (and are macros in <secure/_string.h>),
   so we don’t provide our own fallback there. On Linux, define them here. */
#if !defined(__APPLE__)
  /* Remove any existing macro to avoid “expected parameter declarator” */
  #undef strlcat
  static inline size_t
  strlcat(char *dst, const char *src, size_t dstsize)
  {
      const char *odst = dst;
      size_t n = dstsize;
      size_t dlen;

      while (n-- != 0 && *dst != '\0')
          dst++;
      dlen = dst - odst;
      n = dstsize - dlen;
      if (n == 0)
          return (dlen + strlen(src));
      size_t copy_n = dstsize - dlen - 1;
      if (copy_n > strlen(src))
          copy_n = strlen(src);
      memcpy(dst + dlen, src, copy_n);
      dst[dlen + copy_n] = '\0';
      return (dlen + strlen(src));
  }

  #undef strlcpy
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
      if (n == 0 && dstsize != 0)
          *dst = '\0';
      while (*src++)
          ;
      return (src - osrc - 1);
  }

  #undef strnstr
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
#endif /* !__APPLE__ */

#endif /* TESTS_H */
