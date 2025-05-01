/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:53:27 by acossari          #+#    #+#             */
/*   Updated: 2025/05/01 17:32:27 by acossari         ###   ########.fr       */
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