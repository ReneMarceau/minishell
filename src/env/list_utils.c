/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:25:30 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/09 13:19:48 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "env.h"

int count_node_env(t_env *head)
{
    int     count;

    count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

t_env   *create_node_env(char *key, char *value)
{
    t_env   *new_node;

    new_node = (t_env *)ft_calloc(1, sizeof(t_env));
    if (new_node == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    new_node->key = ft_strdup(key);
    if (new_node->key == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    new_node->value = ft_strdup(value);
    if (new_node->value == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    new_node->next = NULL;
    return (new_node);
}

void    insert_env(t_env **head, t_env *new_node)
{
    t_env  *tmp;

    if (new_node == NULL)
        return ;
    tmp = *head;
    if (*head)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    else
        *head = new_node;
}
