/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:09 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:32 by acossari         ###   ########.fr       */
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

	/* 1. Write a string ending with newline */
	memset(buf, 0, sizeof(buf));
	ft_putendl_fd("Hello", fd[1]);
	ret = read(fd[0], buf, 6);
	assert(ret == 6);
	assert(strncmp(buf, "Hello\n", 6) == 0);

	/* 2. Empty string should still write a newline */
	memset(buf, 0, sizeof(buf));
	ret = 0;
	ft_putendl_fd("", fd[1]);
	ret = read(fd[0], buf, 1);
	assert(ret == 1);
	assert(buf[0] == '\n');

	/* 3. Multiple calls in sequence */
	memset(buf, 0, sizeof(buf));
	ft_putendl_fd("Foo", fd[1]);
	ft_putendl_fd("Bar", fd[1]);
	ret = read(fd[0], buf, 8);
	assert(ret == 8);
	/* Expect "Foo\nBar\n" */
	assert(strncmp(buf, "Foo\nBar\n", 8) == 0);

	/* 4. FD close behavior: should not crash on closed fd */
	close(fd[1]);
	ft_putendl_fd("Test", fd[1]);

	return (0);
}
