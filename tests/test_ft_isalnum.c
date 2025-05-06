/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:44 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:18 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* alphabetic characters */
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('Z') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('z') == 1);

	/* numeric characters */
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('5') == 1);
	assert(ft_isalnum('9') == 1);

	/* non-alphanumeric characters */
	assert(ft_isalnum('!') == 0);
	assert(ft_isalnum(' ') == 0);
	assert(ft_isalnum('\n') == 0);
	assert(ft_isalnum('@') == 0);

	/* values just outside the alnum ranges */
	assert(ft_isalnum('A' - 1) == 0);
	assert(ft_isalnum('Z' + 1) == 0);
	assert(ft_isalnum('a' - 1) == 0);
	assert(ft_isalnum('z' + 1) == 0);
	assert(ft_isalnum('0' - 1) == 0);
	assert(ft_isalnum('9' + 1) == 0);

	/* negative and >127 values should be treated as non-alphanumeric */
	assert(ft_isalnum(-1) == 0);
	assert(ft_isalnum(128) == 0);

	return (0);
}
