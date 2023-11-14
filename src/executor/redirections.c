/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:05:48 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/13 11:15:30 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "executor.h"
#include "error.h"

bool    handle_pipe_redirections(t_shell *shell,  t_cmd *cmd)
{
    if (cmd->index > 0)
    {
        if (dup2(shell->pipe_fd[cmd->index - 1][READ_END], STDIN_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
    }
    else if (cmd->next != NULL)
    {
        if (dup2(shell->pipe_fd[cmd->index][WRITE_END], STDOUT_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
    }
    close_pipes(shell);
    return (true);
}
