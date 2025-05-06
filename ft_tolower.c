/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:54 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:41:17 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_tolower:
 *   Convert uppercase letter `c` to lowercase if it is in 'A'–'Z'.
 *   Returns `c` unchanged otherwise.
 */
int	ft_tolower(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc >= 'A' && uc <= 'Z')
		return (uc - 'A' + 'a');
	return (c);
}
