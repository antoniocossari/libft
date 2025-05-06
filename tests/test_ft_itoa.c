/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:55 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:00 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	*res;

	/* 1. Zero */
	res = ft_itoa(0);
	assert(res != NULL && strcmp(res, "0") == 0);
	free(res);

	/* 2. Positive numbers */
	res = ft_itoa(42);
	assert(res != NULL && strcmp(res, "42") == 0);
	free(res);

	res = ft_itoa(123456);
	assert(res != NULL && strcmp(res, "123456") == 0);
	free(res);

	/* 3. Negative numbers */
	res = ft_itoa(-1);
	assert(res != NULL && strcmp(res, "-1") == 0);
	free(res);

	res = ft_itoa(-98765);
	assert(res != NULL && strcmp(res, "-98765") == 0);
	free(res);

	/* 4. INT_MAX and INT_MIN */
	res = ft_itoa(INT_MAX);
	assert(res != NULL && strcmp(res, "2147483647") == 0);
	free(res);

	res = ft_itoa(INT_MIN);
	assert(res != NULL && strcmp(res, "-2147483648") == 0);
	free(res);

	return (0);
}
