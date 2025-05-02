/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:42 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:14:16 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_memcmp:
 *   Compare the first `n` bytes of `s1` and `s2`.
 *   Return a negative value if `s1` is less than `s2`,
 *   zero if they are equal, or a positive value if `s1` is greater.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return ((int)p1[i] - (int)p2[i]);
		i++;
	}
	return (0);
}
