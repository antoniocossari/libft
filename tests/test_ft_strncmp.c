/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:28 by acossari          #+#    #+#             */
/*   Updated: 2025/05/09 22:51:38 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>
#include <assert.h>

/* Helper per ricavare il segno di un intero */
static int sign(int x)
{
    return (x > 0) - (x < 0);
}

int main(void)
{
    int ft, std;

    /* 1. n = 0 → 0 */
    ft  = ft_strncmp("foo", "bar", 0);
    std = strncmp("foo", "bar", 0);
    assert(sign(ft) == sign(std));

    /* 2. Stringhe uguali */
    ft  = ft_strncmp("", "", 1);
    std = strncmp("", "", 1);
    assert(sign(ft) == sign(std));

    ft  = ft_strncmp("abc", "abc", 3);
    std = strncmp("abc", "abc", 3);
    assert(sign(ft) == sign(std));

    /* 3. Mismatch dentro n */
    ft  = ft_strncmp("abc", "abd", 3);
    std = strncmp("abc", "abd", 3);
    assert(sign(ft) == sign(std));

    ft  = ft_strncmp("abd", "abc", 3);
    std = strncmp("abd", "abc", 3);
    assert(sign(ft) == sign(std));

    /* 4. Non confronta oltre n */
    ft  = ft_strncmp("abcX", "abcY", 3);
    std = strncmp("abcX", "abcY", 3);
    assert(sign(ft) == sign(std));

    /* 5. n più grande delle lunghezze (ferma al NUL) */
    ft  = ft_strncmp("abc", "abc", 10);
    std = strncmp("abc", "abc", 10);
    assert(sign(ft) == sign(std));

    /* 6. Uno vuoto vs uno non vuoto */
    ft  = ft_strncmp("", "a", 1);
    std = strncmp("", "a", 1);
    assert(sign(ft) == sign(std));

    ft  = ft_strncmp("a", "", 1);
    std = strncmp("a", "", 1);
    assert(sign(ft) == sign(std));

    /* 7. Casi misti */
    ft  = ft_strncmp("hello", "helium", 3);
    std = strncmp("hello", "helium", 3);
    assert(sign(ft) == sign(std));

    ft  = ft_strncmp("hello", "helium", 4);
    std = strncmp("hello", "helium", 4);
    assert(sign(ft) == sign(std));

    return 0;
}
