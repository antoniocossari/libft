/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:29 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:03:04 by antoniocoss      ###   ########.fr       */
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
	return (c >= 0 && c <= 126);
}
