/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:45 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/05 10:24:18 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "builtin.h"

bool    is_builtin(char *cmd_name)
{
    if (ft_strlen(cmd_name) == 0)
        return (false);
    if (ft_strcmp(cmd_name, "echo") == true)
        return (true);
    if (ft_strcmp(cmd_name, "cd") == true)
        return (true);
    if (ft_strcmp(cmd_name, "pwd") == true)
        return (true);
    if (ft_strcmp(cmd_name, "export") == true)
        return (true);
    if (ft_strcmp(cmd_name, "unset") == true)
        return (true);
    if (ft_strcmp(cmd_name, "env") == true)
        return (true);
    if (ft_strcmp(cmd_name, "exit") == true)
        return (true);
    return (false);
}

bool    exec_builtin(t_cmd *cmd, t_env *env)
{
    char *cmd_name;

    cmd_name = cmd->args[0];
    if (ft_strcmp(cmd_name, "echo") == true)
        return (exec_echo(cmd));
    if (ft_strcmp(cmd_name, "cd") == true)
        return (exec_cd(cmd, env));
    if (ft_strcmp(cmd_name, "pwd") == true)
        return (exec_pwd(cmd));
    if (ft_strcmp(cmd_name, "export") == true)
        return (exec_export(cmd, env));
    if (ft_strcmp(cmd_name, "unset") == true)
        return (exec_unset(cmd, env));
    if (ft_strcmp(cmd_name, "env") == true)
        return (exec_env(cmd, env));
    if (ft_strcmp(cmd_name, "exit") == true)
        return (exec_exit(cmd));
    
    return (print_error(ERR_CMD_NF, cmd_name, 127), false);
}

char    *get_env_value(t_env *env, char *key)
{
    t_env *current;

    current = env;
    while (current != NULL)
    {
        if (ft_strcmp(current->key, key) == true)
            return (current->value);
        current = current->next;
    }
    return (NULL);
}

void    set_env_value(t_env *env, char *key, char *value)
{
    t_env *current;

    current = env;
    while (current != NULL)
    {
        if (ft_strcmp(current->key, key) == true)
        {
            free(current->value);
            current->value = ft_strdup(value);
            return ;
        }
        current = current->next;
    }
}
