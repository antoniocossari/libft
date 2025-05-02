/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:59 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:42:19 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_toupper:
 *   Convert lowercase letter `c` to uppercase if it is in 'a'–'z';
 *   otherwise return `c` unchanged.
 */
int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc >= 'a' && uc <= 'z')
		return (uc - 'a' + 'A');
	return (c);
}
