/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:45 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/07 14:19:46 by rmarceau         ###   ########.fr       */
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

bool    exec_builtin(t_cmd *cmd, t_env *env, t_shell *shell)
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
        return (exec_exit(shell, cmd));
    
    return (print_error(ERR_CMD_NF, cmd_name, 127), false);
}

bool    is_valid_identifier(char **args)
{
    int i;
    int j;

    i = 0;
    while (args[++i] != NULL)
    {
        if (args[i][0] == '=')
            return (print_error_builtin(ERR_INVALID_ID, args[0], args[i], 1), false);
        if (ft_isalpha(args[i][0]) == 0 && args[i][0] != '_')
            return (print_error_builtin(ERR_INVALID_ID, args[0], args[i], 1), false);
        j = -1;
        while (args[i][++j] != '\0')
        {
            if (args[i][j] == '=')
                continue ;
            if (ft_isalnum(args[i][j]) == 0 && args[i][j] != '_')
                return (print_error_builtin(ERR_INVALID_ID, args[0], args[i], 1), false);
        }
    }
    return (true);
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
