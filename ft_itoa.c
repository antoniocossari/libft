/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:53:27 by acossari          #+#    #+#             */
/*   Updated: 2025/05/04 16:08:16 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* get_len:
 *   returns how many characters are needed for nbr (incl. '-' e '\0')
 */
static size_t	get_len(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*
 * ft_itoa:
 *   Convert the integer `n` to a null-terminated string.
 *   Handles `0` by returning "0" and negative values by
 *   prepending '-'. Allocates memory with malloc;
 *   caller must free the returned string.
 */
char	*ft_itoa(int n)
{
	long	nbr;
	size_t	len;
	char	*res;

	nbr = n;
	len = get_len(nbr);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	res[len] = '\0';
	if (nbr == 0)
		res[0] = '0';
	while (nbr)
	{
		res[--len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (res);
}
