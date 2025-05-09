/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:33:59 by acossari          #+#    #+#             */
/*   Updated: 2025/05/07 18:10:06 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int main(void)
{
    t_list  *list = NULL;
    t_list  *n1   = ft_lstnew(strdup("first"));
    t_list  *n2   = ft_lstnew(strdup("second"));
    t_list  *n3   = ft_lstnew(strdup("third"));

    /* 1. Add to empty list */
    ft_lstadd_front(&list, n1);
    assert(list == n1);
    assert(list->next == NULL);

    /* 2. Add second node in front */
    ft_lstadd_front(&list, n2);
    assert(list == n2);
    assert(list->next == n1);

    /* 3. Add third node in front */
    ft_lstadd_front(&list, n3);
    assert(list == n3);
    assert(list->next == n2);
    assert(list->next->next == n1);

    /* 4. Passing NULL new node should leave list unchanged */
    int size_before = ft_lstsize(list);
    ft_lstadd_front(&list, NULL);
    assert(ft_lstsize(list) == size_before);

    /* 5. List size reflects number of adds */
    assert(ft_lstsize(list) == 3);

    /* Libera tutta la lista e i contenuti per evitare leak */
    free_list(list);

    return (0);
}
