/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:59 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 12:40:35 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_toupper:
 *   If c is a lowercase ASCII letter, return its uppercase equivalent.
 *   If c is negative, return c unchanged.
 *   Otherwise return c unchanged.
 */
int	ft_toupper(int c)
{
	if (c < 0)
		return c;
	unsigned char uc = (unsigned char)c;
	if (uc >= 'a' && uc <= 'z')
		return (int)(uc - ('a' - 'A'));
	return (int)uc;
}
