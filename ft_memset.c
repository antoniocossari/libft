/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:58 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:16:17 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_memset:
 *   Fill the first `n` bytes of memory area `s` with the constant byte `c`.
 *   Return the pointer to `s`.
 */
void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int main(void)
// {
// 	char buffer[16];

// 	for (int i = 0; i < 15; i++)
// 		buffer[i] = '-';
// 	buffer[15] = '\0';
// 	printf("Prima:  \"%s\"\n", buffer);
// 	ft_memset(buffer, 'A', 10);
// 	printf("Dopo:   \"%s\"\n", buffer);
// 	return 0;
// }
