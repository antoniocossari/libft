/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:08:45 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 22:45:01 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_isalnum:
 *   Check if `c` is an alphabetic letter or a digit.
 *   Returns non-zero if true, zero otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
