/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:13 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 18:09:52 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int main(void)
{
    /* 1. Integer content allocated on heap */
    int *val = malloc(sizeof(int));
    *val = 42;
    t_list *n1 = ft_lstnew(val);
    assert(n1);
    assert(n1->content == val);
    assert(n1->next == NULL);

    /* 2. String content duplicated on heap */
    char *s = strdup("hello");
    t_list *n2 = ft_lstnew(s);
    assert(n2);
    assert(n2->content == s);
    assert(n2->next == NULL);

    /* 3. NULL content */
    t_list *n3 = ft_lstnew(NULL);
    assert(n3);
    assert(n3->content == NULL);
    assert(n3->next == NULL);

    /* 4. Nodes are distinct and contents differ */
    assert(n1 != n2);
    assert(n2 != n3);
    assert(n1->content != n2->content);

    /* 5. Next pointers remain NULL */
    assert(n1->next == NULL);
    assert(n2->next == NULL);
    assert(n3->next == NULL);

    /* free all nodes and their content to avoid leaks */
    free_list(n1);
    free_list(n2);
    free_list(n3);

    return 0;
}
