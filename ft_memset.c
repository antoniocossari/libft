/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:09:58 by acossari          #+#    #+#             */
/*   Updated: 2025/04/24 16:10:00 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	// Cast del puntatore generico a puntatore ad unsigned char per assicurarci
	// Per garantire che ogni assegnazione scriva esattamente un “byte” senza segni ecc
	p = (unsigned char *)b;                 
	i = 0;
	while (i < n)                            // ripeti fino a n byte, non e una string ama un'area di memoria
	{
		p[i] = (unsigned char)c;             // Castiamo c a unsigned char per ottenere il valore tra 0 e 255.
		i++;
	}
	return (b); // restituisce il puntatore originale a inizio buffer
}

int main(void)
{
	char buffer[16];

	// Inizializziamo buffer con un pattern riconoscibile
	for (int i = 0; i < 15; i++)
		buffer[i] = '-';
	buffer[15] = '\0'; // La 16esima posizione

	printf("Prima:  \"%s\"\n", buffer);

	// Riempie i primi 10 byte con 'A'
	ft_memset(buffer, 'A', 10);

	printf("Dopo:   \"%s\"\n", buffer);

	return 0;
}