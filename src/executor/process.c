/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:58:00 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/28 10:40:57 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "builtin.h"
#include "error.h"

bool init_processes(t_shell *shell)
{
	t_cmd	*cmd;
	int		i;

	cmd	= shell->cmd_table;
	i = 0;
	shell->pids = (pid_t *)ft_calloc(shell->nb_cmd, sizeof(pid_t));
	if (shell->pids == NULL)
		return (print_error(ERR_MALLOC, NULL), false);
	if (is_builtin(cmd->args[0]) == true && cmd->next == NULL)
	{
		shell->pids[i] = 0;
		cmd->pid = shell->pids[i];
		return (true);
	}
	while (i < shell->nb_cmd)
	{
		shell->pids[i] = fork();
		if (shell->pids[i] == -1)
			return (print_error(ERR_FORK, NULL), false);
		else if (shell->pids[i] == 0)
		{
			cmd->pid = shell->pids[i];
			return (true);
		}
		cmd->pid = shell->pids[i];
		cmd = cmd->next;
		i++;
	}
	return (true);
}

bool	init_pipes(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->nb_cmd > 1)
	{
		shell->pipe_fd = (int **)ft_calloc(shell->nb_cmd - 1, sizeof(int *));
		if (shell->pipe_fd == NULL)
			return (print_error(ERR_MALLOC, NULL), false);
		while (i < (shell->nb_cmd - 1))
		{
			shell->pipe_fd[i] = (int *)ft_calloc(2, sizeof(int));
			if (shell->pipe_fd[i] == NULL)
				return (print_error(ERR_MALLOC, NULL), false);
			if (pipe(shell->pipe_fd[i]) == -1)
				return (print_error(ERR_PIPE, NULL), false);
			i++;
		}
	}
	return (true);
}

void    wait_all(pid_t *pids, int nb_cmds)
{
    int i;
    
    i = 0;
    while (i < nb_cmds)
    {
        waitpid(pids[i], &g_exit_status, 0);
        i++;
    }
}
