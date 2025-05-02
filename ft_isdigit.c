/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:23 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:02:32 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_isdigit:
 *   Check if `c` is a decimal digit character ('0' to '9').
 *   Returns non-zero if true, zero otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
