/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:08:37 by acossari          #+#    #+#             */
/*   Updated: 2025/04/30 18:07:03 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	/* Evitiamo overflow in nmemb * size */
	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	/* Calcoliamo il numero totale di byte da allocare */
	total = nmemb * size;
	/* Se nmemb o size è 0, malloc(0) può restituire NULL o un puntatore liberabile */
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	/* Inizializziamo a zero tutti i byte allocati */
	ft_memset(ptr, 0, total);
	return (ptr);
}
