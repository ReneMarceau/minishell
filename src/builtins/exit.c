/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:55 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/07 14:38:45 by rmarceau         ###   ########.fr       */
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

bool    exec_exit(t_shell *shell, t_cmd *cmd)
{
    if (cmd->next == NULL)
        printf("exit\n");
    if (cmd->args[1] != NULL)
    {
        if (ft_isnumber(cmd->args[1]) == false)
        {
            print_error_builtin(ERR_NUMERIC_ARG, cmd->args[0], cmd->args[1], 255);
            exit_shell(shell, true);
        }
        if (cmd->args[2] != NULL)
        {
            print_error_builtin(ERR_TOO_MANY_ARGS, cmd->args[0], NULL, 1);
            return (false);
        }
        g_exit_status = ft_atoi(cmd->args[1]);
        exit_shell(shell, true);
    }
    exit_shell(shell, true);
    return (true);
}
