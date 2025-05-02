/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:00 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 22:53:10 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_isascii:
 *   Check if `c` is a 7-bit ASCII character (0–127).
 *   Returns non-zero if true, zero otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
