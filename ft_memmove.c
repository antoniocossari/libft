/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:52 by acossari          #+#    #+#             */
/*   Updated: 2025/05/05 19:58:00 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_memmove:
 *   Copy `n` bytes from memory area `src` to `dest`,
 *   handling overlapping regions safely by copying
 *   in the correct direction. Return `dest`.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			*(d + n) = *(s + n);
	return (dest);
}
