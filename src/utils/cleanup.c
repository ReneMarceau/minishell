/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:52:40 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/29 01:28:16 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"

bool    close_pipes(t_shell *shell)
{
    int  i;

    i = 0;
    while (i < (shell->nb_cmd - 1))
    {
        if (close(shell->pipe_fd[i][READ_END]) == -1)
            return (print_error(ERR_CLOSE, NULL, EXIT_FAILURE), false);
        if (close(shell->pipe_fd[i][WRITE_END]) == -1)
            return (print_error(ERR_CLOSE, NULL, EXIT_FAILURE), false);
        i++;
    }
    return (true);
}
