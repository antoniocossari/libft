/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:53 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:04 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* printable characters (32 to 126 inclusive) */
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint('~') == 1);
	assert(ft_isprint('A') == 1);
	assert(ft_isprint('z') == 1);
	assert(ft_isprint('!') == 1);

	/* non-printable characters */
	assert(ft_isprint('\t') == 0);
	assert(ft_isprint('\n') == 0);
	assert(ft_isprint('\r') == 0);
	assert(ft_isprint(31) == 0);
	assert(ft_isprint(127) == 0);

	return (0);
}
