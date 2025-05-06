/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:50 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:10 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* Valid ASCII range: 0 through 127 */
	assert(ft_isascii(0) == 1);
	assert(ft_isascii(127) == 1);
	assert(ft_isascii(65) == 1);   /* 'A' */
	assert(ft_isascii(10) == 1);   /* newline */

	/* Outside ASCII range */
	assert(ft_isascii(-1) == 0);
	assert(ft_isascii(128) == 0);
	assert(ft_isascii(255) == 0);

	/* Some random in-range values */
	assert(ft_isascii(32) == 1);   /* space */
	assert(ft_isascii(126) == 1);  /* '~' */

	return (0);
}
