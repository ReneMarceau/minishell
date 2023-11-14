/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:41:50 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/10 14:19:06 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "env.h"

static bool    split_key_value(char *env, char **key, char **value)
{
    char    *equal_sign_pos;

    equal_sign_pos = ft_strchr(env, '=');
    if (equal_sign_pos != NULL)
    {
        *key = ft_substr(env, 0, equal_sign_pos - env);
        if (*key == NULL)
            return (print_error(ERR_MALLOC, NULL), false);
        *value = ft_strdup(equal_sign_pos + 1);
        if (*value == NULL)
            return (print_error(ERR_MALLOC, NULL), false);
    }
    return (true);
}

static char    *combine_key_value(char *key, char *value)
{
    char    *key_value;
    char    *tmp;

    tmp = ft_strjoin(key, "=");
    if (tmp == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    key_value = ft_strjoin(tmp, value);
    if (key_value == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    free(tmp);
    return (key_value);
}

t_env   *build_env_list(char **env)
{
    t_env   *head;
    char    *key;
    char    *value;
    int     i;

    head = NULL;
    i = 0;
    while (env[i] != NULL)
    {
        key = NULL;
        value = NULL;
        if (split_key_value(env[i], &key, &value) == false)
            return (NULL);
        if (key != NULL && value != NULL)
        {
            insert_env(&head, create_node_env(key, value));
            free(key);
            free(value);
        }
        i++;
    }
    return (head);
}

char    **env_to_array(t_env *head)
{
    char    **env_array;
    int     node_count;
    int     i;

    node_count = count_node_env(head);
    env_array = (char **)ft_calloc(node_count + 1, sizeof(char *));
    if (env_array == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    i = 0;
    while (i < node_count)
    {
        env_array[i] = combine_key_value(head->key, head->value);
        if (env_array[i] == NULL)
            return (NULL);
        head = head->next;
        i++;
    }
    env_array[i] = NULL;
    return (env_array);
}

