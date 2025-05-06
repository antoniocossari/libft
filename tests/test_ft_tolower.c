/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:37 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:22 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* uppercase letters should be converted */
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('Z') == 'z');
	
	/* lowercase letters remain unchanged */
	assert(ft_tolower('a') == 'a');
	assert(ft_tolower('z') == 'z');
	
	/* non-alphabetic characters remain unchanged */
	assert(ft_tolower('0') == '0');
	assert(ft_tolower('!') == '!');
	assert(ft_tolower(' ') == ' ');
	
	/* values just outside uppercase range */
	assert(ft_tolower('A' - 1) == 'A' - 1);
	assert(ft_tolower('Z' + 1) == 'Z' + 1);
	
	/* negative and large values treated as unchanged */
	assert(ft_tolower(-1) == -1);
	assert(ft_tolower(128) == 128);

	return (0);
}
