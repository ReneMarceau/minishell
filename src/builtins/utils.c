/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:45 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/29 23:23:20 by rene             ###   ########.fr       */
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
