/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:47 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:39:17 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_strrchr:
 *   Locate the last occurrence of character `c` in the string `s`.
 *   The terminating null byte is considered part of the string.
 *   Return a pointer to the matching byte or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	if (last)
		return ((char *)last);
	return (NULL);
}
