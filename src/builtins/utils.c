/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:45 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/16 15:52:02 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
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

bool    exec_builtin(char *cmd_name)
{
    int cmd_length;

    cmd_length = ft_strlen(cmd_name);
    if (ft_strncmp(cmd_name, "echo", cmd_length) == 0)
        return (ft_putendl_fd("executing cmd: echo", 1), true);
    if (ft_strncmp(cmd_name, "cd", cmd_length) == 0)
        return (ft_putendl_fd("executing cmd: cd", 1), true);
    if (ft_strncmp(cmd_name, "pwd", cmd_length) == 0)
        return (ft_putendl_fd("executing cmd: pwd", 1), true);
    if (ft_strncmp(cmd_name, "export", cmd_length) == 0)
        return (ft_putendl_fd("executing cmd: export", 1), true);
    if (ft_strncmp(cmd_name, "unset", cmd_length) == 0)
        return (ft_putendl_fd("executing cmd: unset", 1), true);
    if (ft_strncmp(cmd_name, "env", cmd_length) == 0)
        return (ft_putendl_fd("executing cmd: env", 1), true);
    if (ft_strncmp(cmd_name, "exit", cmd_length) == 0)
        return (ft_putendl_fd("executing cmd: exit", 1), true);
    return (false);
}
