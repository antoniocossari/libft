/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:57:15 by acossari          #+#    #+#             */
/*   Updated: 2025/05/01 19:00:34 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_striteri:
 * Applica la funzione f a ogni carattere di s,
 * passando indice e indirizzo del carattere.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;  /* indice corrente */

	if (!s || !f)
		return;         /* niente da fare se input o funzione non valida */
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);  /* f può leggere/alterare s[i] */
		i++;
	}
}


