/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:45 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/18 01:53:36 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "builtin.h"

bool    is_builtin(char *cmd_name)
{
    int cmd_length;

    cmd_length = ft_strlen(cmd_name);
    if (ft_strncmp(cmd_name, "echo", cmd_length) == 0)
        return (true);
    if (ft_strncmp(cmd_name, "cd", cmd_length) == 0)
        return (true);
    if (ft_strncmp(cmd_name, "pwd", cmd_length) == 0)
        return (true);
    if (ft_strncmp(cmd_name, "export", cmd_length) == 0)
        return (true);
    if (ft_strncmp(cmd_name, "unset", cmd_length) == 0)
        return (true);
    if (ft_strncmp(cmd_name, "env", cmd_length) == 0)
        return (true);
    if (ft_strncmp(cmd_name, "exit", cmd_length) == 0)
        return (true);
    return (false);
}

bool    exec_builtin(t_cmd *cmd, t_env *env)
{
    char *cmd_name;
    int cmd_length;

    cmd_name = cmd->args[0];
    cmd_length = ft_strlen(cmd_name);
    if (ft_strncmp(cmd_name, "echo", cmd_length) == 0)
        return (exec_echo(cmd));
    if (ft_strncmp(cmd_name, "cd", cmd_length) == 0)
        return (exec_cd(cmd, env));
    if (ft_strncmp(cmd_name, "pwd", cmd_length) == 0)
        return (exec_pwd(cmd));
    if (ft_strncmp(cmd_name, "export", cmd_length) == 0)
        return (exec_export(cmd, env));
    if (ft_strncmp(cmd_name, "unset", cmd_length) == 0)
        return (exec_unset(cmd, env));
    if (ft_strncmp(cmd_name, "env", cmd_length) == 0)
        return (exec_env(cmd, env));
    if (ft_strncmp(cmd_name, "exit", cmd_length) == 0)
        return (exec_exit(cmd));
    return (false);
}
