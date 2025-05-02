/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:53:27 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:12:08 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* restituisce il numero di cifre necessarie per rappresentare nbr */
static size_t	get_len(long nbr)
{
	size_t	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr /= 10;
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
	size_t	i;
	char	*res;

	nbr = n;
	len = get_len(nbr);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		res[0] = '0';
	i = len - 1;
	while (nbr > 0)
	{
		res[i] = '0' + (nbr % 10);
		nbr /= 10;
		i--;
	}
	return (res);
}
