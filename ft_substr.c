/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:24:30 by acossari          #+#    #+#             */
/*   Updated: 2025/04/30 18:43:33 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_substr:
 * Allocates (with malloc) and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is at most ’len’ characters long.
 * If allocation fails, returns NULL.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	/* Se s è NULL, non possiamo creare una sottostringa: ritorniamo NULL. */
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	/* If start is beyond the end of s, return an empty string */
	if (start >= s_len)
		len = 0;
	/* Don't read past the end: adjust len to remaining chars */
	else if (s_len - start < len)
		len = s_len - start;
	/* Allocate space for len characters + terminating '\0' */
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	/* Copy up to len characters from s + start into substr */
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';  /* Null‐terminate */
	return (substr);
}
