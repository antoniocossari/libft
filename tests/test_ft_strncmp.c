/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:49:28 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:42 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/*
 * tests for ft_strncmp – no dynamic memory, all literals
 */
int main(void)
{
    /* 1. n = 0 should always return 0 */
    assert(ft_strncmp("foo", "bar", 0) == strncmp("foo", "bar", 0));

    /* 2. Equal strings */
    assert(ft_strncmp("", "", 1) == strncmp("", "", 1));
    assert(ft_strncmp("abc", "abc", 3) == strncmp("abc", "abc", 3));

    /* 3. Difference within n */
    assert(ft_strncmp("abc", "abd", 3) == strncmp("abc", "abd", 3));
    assert(ft_strncmp("abd", "abc", 3) == strncmp("abd", "abc", 3));

    /* 4. Difference beyond n (should not compare) */
    assert(ft_strncmp("abcX", "abcY", 3) == strncmp("abcX", "abcY", 3));

    /* 5. n larger than both lengths (stop at NUL) */
    assert(ft_strncmp("abc", "abc", 10) == strncmp("abc", "abc", 10));

    /* 6. One empty, one non-empty */
    assert(ft_strncmp("", "a", 1) == strncmp("", "a", 1));
    assert(ft_strncmp("a", "", 1) == strncmp("a", "", 1));

    /* 7. Partial compares */
    assert(ft_strncmp("hello", "helium", 3) == strncmp("hello", "helium", 3));
    assert(ft_strncmp("hello", "helium", 4) == strncmp("hello", "helium", 4));

    return 0;
}
