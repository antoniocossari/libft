/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:24 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:29 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	/* 1. Empty and spaces */
	assert(ft_atoi("") == 0);
	assert(ft_atoi("    ") == 0);

	/* 2. Positive numbers */
	assert(ft_atoi("0") == 0);
	assert(ft_atoi("42") == 42);
	assert(ft_atoi("   123") == 123);

	/* 3. Negative numbers */
	assert(ft_atoi("-1") == -1);
	assert(ft_atoi("  -999") == -999);

	/* 4. Explicit signs */
	assert(ft_atoi("+7") == 7);
	assert(ft_atoi("-0") == 0);

	/* 5. Limits */
	assert(ft_atoi("2147483647") == INT_MAX);
	assert(ft_atoi("-2147483648") == INT_MIN);

	/* 6. Stop at non-digits */
	assert(ft_atoi("123abc") == 123);
	assert(ft_atoi("   -45xyz") == -45);

	return 0;
}