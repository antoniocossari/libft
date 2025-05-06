/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniocossari <antoniocossari@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:03:07 by acossari          #+#    #+#             */
/*   Updated: 2025/05/02 23:35:31 by antoniocoss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char to_upper_even(unsigned int i, char c)
// {
// 	// Se l’indice è pari e c è una lettera minuscola, la trasformo in maiuscola
// 	if (i % 2 == 0 && c >= 'a' && c <= 'z')
// 		return (c - 'a' + 'A');
// 	// altrimenti lascio c invariato
// 	return (c);
// }

/*
 * ft_strmapi:
 *   Apply function `f` to each character of `s`, with index `i`,
 *   and return a new malloc’ed string of the results.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int main(void)
// {
// 	char	*s = "abcdef";
// 	char	*t;

// 	t = ft_strmapi(s, to_upper_even);
// 	if (!t)
// 	{
// 		perror("ft_strmapi failed");
// 		return (1);
// 	}

// 	printf("Originale: %s\n", s);
// 	printf("Risultato: %s\n", t);

// 	free(t);
// 	return (0);
// }
