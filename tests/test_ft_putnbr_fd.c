/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:11 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:28 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	buf[16];
	int		fd[2];
	ssize_t	ret;

	/* create a pipe */
	assert(pipe(fd) == 0);

	/* 1. Zero */
	ft_putnbr_fd(0, fd[1]);
	ret = read(fd[0], buf, 1);
	assert(ret == 1);
	assert(buf[0] == '0');

	/* 2. Positive number */
	memset(buf, 0, sizeof(buf));
	ft_putnbr_fd(12345, fd[1]);
	ret = read(fd[0], buf, strlen("12345"));
	assert(ret == 5);
	assert(strncmp(buf, "12345", 5) == 0);

	/* 3. Negative number */
	memset(buf, 0, sizeof(buf));
	ft_putnbr_fd(-987, fd[1]);
	ret = read(fd[0], buf, strlen("-987"));
	assert(ret == 4);
	assert(strncmp(buf, "-987", 4) == 0);

	/* 4. INT_MAX and INT_MIN */
	memset(buf, 0, sizeof(buf));
	ft_putnbr_fd(INT_MAX, fd[1]);
	ret = read(fd[0], buf, strlen("2147483647"));
	assert(ret == 10);
	assert(strncmp(buf, "2147483647", 10) == 0);

	memset(buf, 0, sizeof(buf));
	ft_putnbr_fd(INT_MIN, fd[1]);
	ret = read(fd[0], buf, strlen("-2147483648"));
	assert(ret == 11);
	assert(strncmp(buf, "-2147483648", 11) == 0);

	/* 5. FD close behavior: should not crash on closed fd */
	close(fd[1]);
	ft_putnbr_fd(42, fd[1]);

	return (0);
}
