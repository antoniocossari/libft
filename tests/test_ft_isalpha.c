/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:47 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:14 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* alphabetic characters */
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('Z') == 1);
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('z') == 1);

	/* non-alphabetic but alnum */
	assert(ft_isalpha('0') == 0);
	assert(ft_isalpha('9') == 0);

	/* non-alphabetic characters */
	assert(ft_isalpha('!') == 0);
	assert(ft_isalpha(' ') == 0);
	assert(ft_isalpha('\n') == 0);

	/* values just outside letter ranges */
	assert(ft_isalpha('A' - 1) == 0);
	assert(ft_isalpha('Z' + 1) == 0);
	assert(ft_isalpha('a' - 1) == 0);
	assert(ft_isalpha('z' + 1) == 0);

	/* negative and >127 values treated as false */
	assert(ft_isalpha(-1) == 0);
	assert(ft_isalpha(128) == 0);

	return (0);
}
