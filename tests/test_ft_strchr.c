/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:16 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:19 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	*res;
	char	str[] = "hello world";

	/* 1. Find in middle */
	res = ft_strchr(str, 'o');
	assert(res == strchr(str, 'o'));

	/* 2. Find at beginning */
	res = ft_strchr(str, 'h');
	assert(res == strchr(str, 'h'));

	/* 3. Find at end */
	res = ft_strchr(str, 'd');
	assert(res == strchr(str, 'd'));

	/* 4. Search for '\\0' returns pointer to terminator */
	res = ft_strchr(str, '\0');
	assert(res == strchr(str, '\0'));

	/* 5. Character not found returns NULL */
	res = ft_strchr(str, 'z');
	assert(res == NULL);

	/* 6. Empty string: only '\\0' matches */
	res = ft_strchr("", '\0');
	assert(res != NULL && *res == '\0');
	res = ft_strchr("", 'a');
	assert(res == NULL);

	return (0);
}
