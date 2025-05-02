/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:50:02 by acossari          #+#    #+#             */
/*   Updated: 2025/04/30 18:51:05 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strtrim:
 * Allocates (with malloc) and returns a copy of s1
 * with all characters in set removed from the start and end.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;  /* index of first char not in set */
	size_t	end;    /* index one past last char not in set */
	char	*res;   /* result string */

	if (!s1 || !set)
		return (NULL);
	start = 0;
	/* move start forward past any leading ‘set’ chars */
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	/* move end backward past any trailing ‘set’ chars */
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	/* allocate space for trimmed string + null terminator */
	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	/* copy the trimmed portion in place */
	ft_memcpy(res, s1 + start, end - start);
	res[end - start] = '\0';
	return (res);
}


