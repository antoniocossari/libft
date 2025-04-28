/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:03 by acossari          #+#    #+#             */
/*   Updated: 2025/04/24 16:10:06 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strchr:
 * Searches for the first occurrence of the character 'c' (converted to char)
 * in the string pointed to by 's'. The terminating null byte ('\0') is considered
 * part of the string, so you can search for '\0' to locate the end of the string.
 *
 * Parameters:
 *   s - pointer to the null-terminated string to search in
 *   c - the character to search for (passed as int, but compared as char)
 *
 * Return:
 *   A pointer to the first occurrence of 'c' in 's', or NULL if 'c' is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	// Loop through each character until we hit the terminating '\0'
	while (*s)
	{
		// If the current character matches 'c', return a pointer to it
		if (*s == (char)c)
			return ((char *)s);
		// Advance to the next character
		s++;
	}

	// If we've exited the loop, *s == '\0'. 
	// If we're searching for '\0', return a pointer to the terminator.
	if ((char)c == '\0')
		return ((char *)s);

	// Otherwise, 'c' was not found in the string, return NULL.
	return (NULL);
}