/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:55 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/17 23:00:29 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"

static bool    ft_isnumber(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == false)
            return (false);
        i++;
    }
    return (true);
}

bool    exec_exit(t_cmd *cmd)
{
    if (cmd->next == NULL)
        printf("exit\n");
    if (cmd->args[1] != NULL)
    {
        if (ft_isnumber(cmd->args[1]) == false)
        {
            print_error_builtin(ERR_NUMERIC_ARG, cmd->args[0], cmd->args[1]);
            g_exit_status = 2;
            exit(g_exit_status);
        }
        if (cmd->args[2] != NULL)
        {
            print_error_builtin(ERR_TOO_MANY_ARGS, cmd->args[0], NULL);
            g_exit_status = 1;
            return (false);
        }
        g_exit_status = ft_atoi(cmd->args[1]);
        exit(g_exit_status);
    }
    exit(g_exit_status);
    return (true);
}
