/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:52 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:06 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* digits '0'–'9' */
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit('5') == 1);
	assert(ft_isdigit('9') == 1);

	/* non-digits just outside range */
	assert(ft_isdigit('0' - 1) == 0);
	assert(ft_isdigit('9' + 1) == 0);

	/* other non-digit characters */
	assert(ft_isdigit('a') == 0);
	assert(ft_isdigit(' ') == 0);
	assert(ft_isdigit('\n') == 0);
	assert(ft_isdigit('/') == 0);
	assert(ft_isdigit(':') == 0);

	/* negative and large values */
	assert(ft_isdigit(-1) == 0);
	assert(ft_isdigit(256) == 0);

	return (0);
}
