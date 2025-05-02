/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:52:15 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:29:54 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* conta quante parole separate da 'c' ci sono in s */
static size_t	count_words(const char *s, char c)
{
	size_t	i = 0;
	size_t	count = 0;

	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

/* calcola la lunghezza della parola inizio in s fino a 'c' o '\0' */
static size_t	word_len(const char *s, char c)
{
	size_t	len = 0;

	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/* libera in caso di fallimento tutte le parole già allocate */
static char	**free_split(char **array, size_t allocated)
{
	while (allocated--)
		free(array[allocated]);
	free(array);
	return (NULL);
}

/*
 * ft_split:
 *   Split the string `s` into an array of strings, using `c` as delimiter.
 *   Allocate memory for the array and each substring with malloc.
 *   The array is terminated by a NULL pointer.
 *   Returns NULL if `s` is NULL or an allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	size_t	i = 0;
	size_t	w = 0;
	size_t	words;
	size_t	len;
	char	**array;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (w < words)
	{
		while (s[i] && s[i] == c)
			i++;
		len = word_len(s + i, c);
		array[w] = malloc(len + 1);
		if (!array[w])
			return (free_split(array, w));
		ft_memcpy(array[w], s + i, len);
		array[w][len] = '\0';
		i += len;
		w++;
	}
	array[w] = NULL;
	return (array);
}
