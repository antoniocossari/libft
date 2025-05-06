/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:47 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:14:41 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_memcmp:
 *   Compare the first `n` bytes of `s1` and `s2`.
 *   Return a negative value if `s1` is less than `s2`,
 *   zero if they are equal, or a positive value if `s1` is greater.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
