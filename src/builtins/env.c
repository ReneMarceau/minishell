/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:58 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/11 11:21:16 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "builtin.h"
#include "env.h"
#include "error.h"

bool    exec_env(t_cmd *cmd, t_env *env)
{
    char **env_array;
    int  i;
    
    env_array = env_to_array(env); 
    if (env_array == NULL)
        return (false);
    i = 0;
    if (cmd->args[1] != NULL && cmd->args[1][0] == '-')
        return (print_error_builtin(ERR_INVALID_OPT, cmd->args[0], cmd->args[1], 125), false);
    if (cmd->args[1] != NULL)
        return (print_error_builtin(ERR_NO_SUCH_FD, cmd->args[0], cmd->args[1], 127), false);
    while (env_array[i] != NULL)
    {
        printf("%s\n", env_array[i]);
        i++;
    }
    g_exit_status = EXIT_SUCCESS;
    return (true);
}
