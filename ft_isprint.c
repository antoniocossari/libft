/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:29 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 20:56:38 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_isprint:
 *   Check if `c` is a printable character, including space (ASCII 32–126).
 *   Returns non-zero if true, zero otherwise.
 */
int	ft_isprint(int c)
{
	unsigned char uc = (unsigned char)c;
	return (uc >= ' ' && uc <= '~');
}
