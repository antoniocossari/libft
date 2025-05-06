/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:31 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:34 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	str[] = "hello world";
	char	*res_ft;
	char	*res_std;

	/* find last occurrence in the middle */
	res_ft  = ft_strrchr(str, 'l');
	res_std = strrchr(str, 'l');
	assert(res_ft == res_std);

	/* find at beginning */
	res_ft  = ft_strrchr(str, 'h');
	res_std = strrchr(str, 'h');
	assert(res_ft == res_std);

	/* find at end */
	res_ft  = ft_strrchr(str, 'd');
	res_std = strrchr(str, 'd');
	assert(res_ft == res_std);

	/* search for '\\0' returns pointer to terminator */
	res_ft  = ft_strrchr(str, '\0');
	res_std = strrchr(str, '\0');
	assert(res_ft == res_std);

	/* character not found returns NULL */
	res_ft = ft_strrchr(str, 'z');
	assert(res_ft == NULL);

	/* multiple occurrences: should return last one */
	{
		char	s2[] = "banana";
		res_ft  = ft_strrchr(s2, 'a');
		res_std = strrchr(s2, 'a');
		assert(res_ft == res_std);
	}

	/* empty string: '\\0' matches, other chars not */
	res_ft  = ft_strrchr("", '\0');
	res_std = strrchr("", '\0');
	assert(res_ft == res_std);
	res_ft = ft_strrchr("", 'a');
	assert(res_ft == NULL);

	return (0);
}
