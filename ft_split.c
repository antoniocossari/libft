/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:52:15 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 13:18:12 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * word_len:
 *   returns the number of characters until the next delimiter or
 *   end‐of‐string
 */
static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/* count_words:
 *   counts the number of words in s separated by the delimiter c
 */
static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
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

/* free_split:
 *   frees all previously allocated words in case of an allocation failure
 */
static char	**free_split(char **arr, size_t used)
{
	while (used-- > 0)
		free(arr[used]);
	free(arr);
	return (NULL);
}

/*
 * ft_split:
 *   Split the string `s` into an array of substrings using `c` as delimiter.
 *   Uses ft_substr to allocate and copy each word.
 */
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	w;
	size_t	words;
	char	**arr;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	w = 0;
	while (w < words)
	{
		while (s[i] && s[i] == c)
			i++;
		arr[w] = ft_substr(s, i, word_len(s + i, c));
		if (!arr[w++])
			return (free_split(arr, w - 1));
		i += word_len(s + i, c);
	}
	arr[w] = NULL;
	return (arr);
}
