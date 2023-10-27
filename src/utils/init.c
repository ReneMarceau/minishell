/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:34:52 by rene              #+#    #+#             */
/*   Updated: 2023/10/26 22:01:40 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"

t_shell *init_data(char **envp) {
    t_shell *shell;

    shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
    if (!shell)
        return (print_error(ERR_MALLOC, NULL), NULL);
    shell->cmd_table = NULL;
    shell->nb_cmd = 0;
    shell->pipe_fd[0] = NULL;
    shell->pipe_fd[1] = NULL;
    shell->input_fd = STDIN_FILENO;
    shell->output_fd = STDOUT_FILENO;
    shell->envp = envp;
    return (shell);
}
