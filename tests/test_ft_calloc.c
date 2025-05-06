/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:48:42 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:21 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char	*cptr;
	int		*iptr;
	size_t	i;

	/* Allocate 5 chars and verify zero-initialization */
	cptr = ft_calloc(5, sizeof(char));
	assert(cptr != NULL);
	for (i = 0; i < 5; i++)
		assert(cptr[i] == '\0');
	free(cptr);

	/* Allocate 10 ints and verify zero-initialization */
	iptr = ft_calloc(10, sizeof(int));
	assert(iptr != NULL);
	for (i = 0; i < 10; i++)
		assert(iptr[i] == 0);
	free(iptr);

	/* Single element allocation */
	cptr = ft_calloc(1, 1);
	assert(cptr != NULL);
	assert(cptr[0] == '\0');
	free(cptr);

	return (0);
}
