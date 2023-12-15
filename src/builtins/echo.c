/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:30:00 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/06 15:53:46 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "builtin.h"

bool    is_nflag(const char *arg)
{
    int i;

    i = 1;
    if (arg[0] != '-')
        return (false);
    if (arg[i] == '\0')
        return (false);
    while (arg[i] != '\0')
    {
        if (arg[i] != 'n')
            return (false);
        i++;
    }
    return (true);
}

bool    exec_echo(t_cmd *cmd)
{
    bool    is_newline;
    int     start;

    is_newline = true;
    start = 1;
    while (cmd->args[start] != NULL && is_nflag(cmd->args[start]) == true)
    {
        is_newline = false;
        start++;
    }
    while (cmd->args[start] != NULL)
    {
        printf("%s", cmd->args[start]);
        if (cmd->args[start + 1] != NULL)
            printf(" ");
        start++;
    }
    if (is_newline == true)
        printf("\n");
    //g_exit_status = EXIT_SUCCESS;
    return (true);
}
