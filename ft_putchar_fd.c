/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:24:57 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:44:32 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_putchar_fd:
 *   Write the character `c` to the file descriptor `fd`
 *   using the write() syscall.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
