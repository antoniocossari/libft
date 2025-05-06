/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:57:15 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:31:47 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * ft_striteri:
 *   Apply the function `f` to each character of the mutable string `s`,
 *   passing the character’s index and a pointer to `s[i]` for in-place edits.
 *   Does not return a value.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
