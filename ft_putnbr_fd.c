/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:34:30 by acossari          #+#    #+#             */
/*   Updated: 2025/05/05 19:58:01 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_putnbr_fd:
 *   Write the integer `n` to the file descriptor `fd` as ASCII.
 *   Handles negative values by outputting '-' and using recursion
 *   to print each digit via ft_putchar_fd.
 */
void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd((int)(nbr / 10), fd);
	ft_putchar_fd((char)((nbr % 10) + '0'), fd);
}
