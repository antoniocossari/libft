/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:34 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:37:58 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_strncmp – compare up to n characters of s1 and s2 (unsigned)
 *              returns <0, 0 or >0 exactly as the system strncmp.
 *              stops at the first differing byte or at NUL, never reads past.
 */
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t          i;
	unsigned char   c1;
	unsigned char   c2;

	i = 0;
	while (i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			return 0;
		i++;
	}
	return 0;
}
