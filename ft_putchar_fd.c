/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:24:57 by acossari          #+#    #+#             */
/*   Updated: 2025/05/01 19:29:54 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_putchar_fd:
 * Scrive il carattere c sul file descriptor fd.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}