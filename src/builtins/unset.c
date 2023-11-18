/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:48 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/17 22:18:32 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "env.h"
#include "error.h"

bool    exec_unset(t_cmd *cmd, t_env *env)
{
    int i;

    i = 1;
    if (cmd->args[i] != NULL && cmd->args[1][0] == '-')
        return (print_error_builtin(ERR_INVALID_OPT, cmd->args[0], cmd->args[1]), false);
    while (cmd->args[i] != NULL)
    {
        if (find_env(env, cmd->args[i]) == NULL)
        {
            i++;   
            continue ;
        }
        unset_env(&env, cmd->args[i]);
        i++;
    }
    return (true);
}
