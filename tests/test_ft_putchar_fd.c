/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:06 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:35 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	buf[3];
	int		fd[2];
	ssize_t	ret;

	/* create a pipe */
	assert(pipe(fd) == 0);

	/* 1. Write single character */
	ft_putchar_fd('X', fd[1]);
	ret = read(fd[0], buf, 1);
	assert(ret == 1);
	assert(buf[0] == 'X');

	/* 2. Write newline */
	buf[0] = '\0';
	ret = 0;
	ft_putchar_fd('\n', fd[1]);
	ret = read(fd[0], buf, 1);
	assert(ret == 1);
	assert(buf[0] == '\n');

	/* 3. Multiple writes in sequence */
	ft_putchar_fd('A', fd[1]);
	ft_putchar_fd('B', fd[1]);
	ft_putchar_fd('C', fd[1]);
	ret = read(fd[0], buf, 3);
	assert(ret == 3);
	assert(buf[0] == 'A' && buf[1] == 'B' && buf[2] == 'C');

	/* 4. FD close behavior: should not crash on closed fd */
	close(fd[1]);
	ft_putchar_fd('Z', fd[1]);

	return (0);
}

