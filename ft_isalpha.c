/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:08:52 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 22:45:40 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_isalpha:
 *   Check if `c` is an alphabetic character (A–Z or a–z).
 *   Returns non-zero if true, zero otherwise.
 */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
