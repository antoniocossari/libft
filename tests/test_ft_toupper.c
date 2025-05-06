/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:39 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:18 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* uppercase letters remain unchanged */
	assert(ft_toupper('A') == 'A');
	assert(ft_toupper('Z') == 'Z');

	/* lowercase letters converted to uppercase */
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('m') == 'M');
	assert(ft_toupper('z') == 'Z');

	/* non-alphabetic characters unchanged */
	assert(ft_toupper('0') == '0');
	assert(ft_toupper('!') == '!');
	assert(ft_toupper(' ') == ' ');

	/* values just outside lowercase range */
	assert(ft_toupper('a' - 1) == 'a' - 1);
	assert(ft_toupper('z' + 1) == 'z' + 1);

	/* negative and large values treated as unchanged */
	assert(ft_toupper(-1) == -1);
	assert(ft_toupper(128) == 128);

	return (0);
}
