/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:53 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/06 15:55:40 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "builtin.h"
#include "env.h"
#include "error.h"

static void    print_env(t_env *env)
{
    while (env)
    {
        printf("declare -x %s=\"%s\"\n", env->key, env->value);
        env = env->next;
    }
}

bool    apply_export(char *arg, t_env *env)
{
    char    *key;
    char    *value;
    t_env   *tmp_env;

    key = NULL;
    value = NULL;
    if (ft_strchr(arg, '=') == NULL)
        return (true);
    if (split_key_value(arg, &key, &value) == false)
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
    return (true);
}

bool    exec_export(t_cmd *cmd, t_env *env)
{
    int     i;

    i = 1;
    if (cmd->args[1] == NULL)
        return (print_env(env), true);
    if (cmd->args[1][0] == '-')
        return (print_error_builtin(ERR_INVALID_OPT, cmd->args[0], cmd->args[1], 2), false);
    if (is_valid_identifier(cmd->args) == false)
        return (false);
    while (cmd->args[i] != NULL)
    {
        if (apply_export(cmd->args[i], env) == false)
            return (false);
        i++;
    }
    g_exit_status = EXIT_SUCCESS;
    return (true);
}
