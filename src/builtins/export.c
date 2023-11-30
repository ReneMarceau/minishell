/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:53 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/30 01:23:23 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "env.h"
#include "error.h"

void    print_env(t_env *env)
{
    while (env)
    {
        printf("declare -x %s=\"%s\"\n", env->key, env->value);
        env = env->next;
    }
}

bool    is_valid_identifier(char *str)
{
    int i;

    i = 0;
    if (str[i] == '=')
        return (false);
    while (str[i] != '\0')
    {
        if (str[i] == '=')
            return (true);
        if (ft_isalpha(str[i]) == 0 && str[i] != '_')
            return (false);
        i++;
    }
    return (true);
}

bool    exec_export(t_cmd *cmd, t_env *env)
{
    t_env   *tmp_env;
    char    *key;
    char    *value;
    int     i;

    i = 1;
    if (cmd->args[i] == NULL)
        return (print_env(env), true);
    if (cmd->args[1][0] == '-')
        return (print_error_builtin(ERR_INVALID_OPT, cmd->args[0], cmd->args[1], 2), false);
    if (is_valid_identifier(cmd->args[1]) == false)
        return (print_error_builtin(ERR_INVALID_ID, cmd->args[0], cmd->args[1], 1), false);
    while (cmd->args[i] != NULL)
    {
        key = NULL;
        value = NULL;
        if (ft_strchr(cmd->args[i], '='))
        {
            if (split_key_value(cmd->args[i], &key, &value) == false)
                return (false);
            tmp_env = find_env(env, key);
            if (tmp_env != NULL)
            {
                free(tmp_env->value);
                tmp_env->value = ft_strdup(value);
            }
            else
                insert_env(&env, create_node_env(key, value));
            free(key);
            free(value);
        }
        i++;
    }
    g_exit_status = EXIT_SUCCESS;
    return (true);
}
