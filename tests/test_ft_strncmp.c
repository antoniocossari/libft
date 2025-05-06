/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:28 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:42 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	s1[] = "abcdef";
	char	s2[] = "abcdef";
	char	s3[] = "abcdez";
	char	s4[] = "abcd";
	char	s5[] = "abc";
	size_t	ret_ft;
	size_t	ret_std;

	/* 1. n = 0 → always equal */
	ret_ft  = ft_strncmp(s1, s3, 0);
	ret_std = strncmp(s1, s3, 0);
	assert(ret_ft == ret_std);

	/* 2. identical strings */
	ret_ft  = ft_strncmp(s1, s2, 6);
	ret_std = strncmp(s1, s2, 6);
	assert(ret_ft == 0 && ret_std == 0);

	/* 3. difference within n: 'f'(102) < 'z'(122) → negative */
	ret_ft  = ft_strncmp(s1, s3, 6);
	ret_std = strncmp(s1, s3, 6);
	assert((ret_ft < 0 && ret_std < 0) || (ret_ft > 0 && ret_std > 0));

	/* 4. reverse order → positive */
	ret_ft  = ft_strncmp(s3, s1, 6);
	ret_std = strncmp(s3, s1, 6);
	assert((ret_ft < 0 && ret_std < 0) || (ret_ft > 0 && ret_std > 0));

	/* 5. n shorter than mismatch point: prefix equal */
	ret_ft  = ft_strncmp(s1, s3, 3);
	ret_std = strncmp(s1, s3, 3);
	assert(ret_ft == 0 && ret_std == 0);

	/* 6. comparing up to len of shorter string */
	ret_ft  = ft_strncmp(s1, s4, 6);
	ret_std = strncmp(s1, s4, 6);
	assert((ret_ft > 0 && ret_std > 0) || (ret_ft < 0 && ret_std < 0));

	/* 7. one string shorter, n larger than both lengths */
	ret_ft  = ft_strncmp(s4, s5, 10);
	ret_std = strncmp(s4, s5, 10);
	assert((ret_ft > 0 && ret_std > 0) || (ret_ft < 0 && ret_std < 0));

	return (0);
}
