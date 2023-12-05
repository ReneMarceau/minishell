/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:51 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/29 21:07:13 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "builtin.h"
#include "error.h"

bool    exec_pwd(t_cmd *cmd)
{
    char *pwd;

    if (cmd->args[1] != NULL && cmd->args[1][0] == '-')
        return (print_error_builtin(ERR_INVALID_OPT, cmd->args[0], cmd->args[1], 2), false);
    pwd = getcwd(NULL, 0);
    if (pwd == NULL)
        return (print_error_builtin(ERR_VAR_NOT_SET, cmd->args[0], NULL, 1), false);
    printf("%s\n", pwd);
    free(pwd);
    g_exit_status = EXIT_SUCCESS;
    return (true);
}
