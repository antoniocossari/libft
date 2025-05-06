/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:59 by acossari          #+#    #+#             */
/*   Updated: 2025/05/05 19:58:11 by acossari         ###   ########.fr       */
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
