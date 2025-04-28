/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:47 by acossari          #+#    #+#             */
/*   Updated: 2025/04/24 16:10:49 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strrchr:
 * Cerca l'ultima occorrenza del carattere 'c' (convertito in char)
 * nella stringa terminata da '\0' puntata da 's'.
 *
 * Parametri:
 *   s - puntatore alla stringa in cui cercare
 *   c - carattere da cercare (passato come int, ma confrontato come char)
 *
 * Ritorno:
 *   Puntatore all'ultima occorrenza di 'c' in 's', o NULL se non trovata.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	/* Scorri tutta la stringa, inclusi i caratteri '\0' */
	while (*s)
	{
		if (*s == (char)c)
			last = s;             // aggiorna ogni volta che trovi 'c'
		s++;
	}
	/* Controllo finale sul terminatore '\0' */
	if ((char)c == '\0')
		return ((char *)s);
	/* Se hai trovato almeno un'occorrenza, torna l'ultima */
	if (last)
		return ((char *)last);
	return (NULL);
}
