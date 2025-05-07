/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:12 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 12:23:53 by acossari         ###   ########.fr       */
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

	/* 1. Write a simple string */
	ft_putstr_fd("Hello", fd[1]);
	ret = read(fd[0], buf, strlen("Hello"));
	assert(ret == 5);
	assert(strncmp(buf, "Hello", 5) == 0);

	/* 2. Empty string should write nothing */
	ret = read(fd[0], buf, 0);      /* read 0 bytes → always returns 0 immediately */
	assert(ret == 0);

	/* 3. Multiple writes concatenated */
	memset(buf, 0, sizeof(buf));
	ft_putstr_fd("Foo", fd[1]);
	ft_putstr_fd("Bar", fd[1]);
	ret = read(fd[0], buf, 6);
	assert(ret == 6);
	assert(strncmp(buf, "FooBar", 6) == 0);

	/* 4. Closed descriptor: should not crash */
	close(fd[1]);
	ft_putstr_fd("Test", fd[1]);

	return (0);
}
