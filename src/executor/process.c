/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:58:00 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/15 10:51:10 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "error.h"
#include "garbage_collector.h"
#include "global.h"

bool	init_processes(t_shell *shell)
{
	t_cmd	*cmd;
	int		i;

	cmd = shell->cmd_table;
	i = -1;
	shell->pids = (pid_t *)list_malloc(shell->nb_cmd, sizeof(pid_t));
	if (is_builtin(cmd->args[0]) == true && cmd->next == NULL)
	{
		shell->pids[++i] = 0;
		cmd->pid = shell->pids[i];
		return (true);
	}
	ignore_sigint();
	while (++i < shell->nb_cmd)
	{
		shell->pids[i] = fork();
		if (shell->pids[i] == 0)
		{
			cmd->pid = shell->pids[i];
			return (true);
		}
		cmd->pid = shell->pids[i];
		cmd = cmd->next;
	}
	return (true);
}

bool	init_pipes(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->nb_cmd > 1)
	{
		shell->pipe_fd = (int **)list_malloc(shell->nb_cmd - 1, sizeof(int *));
		if (shell->pipe_fd == NULL)
			return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), false);
		while (i < (shell->nb_cmd - 1))
		{
			shell->pipe_fd[i] = (int *)list_malloc(2, sizeof(int));
			if (shell->pipe_fd[i] == NULL)
				return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), false);
			if (pipe(shell->pipe_fd[i]) == -1)
				return (print_error(ERR_PIPE, NULL, EXIT_FAILURE), false);
			i++;
		}
	}
	return (true);
}

void	wait_all(pid_t *pids, int nb_cmds)
{
	int	i;

	i = 0;
	while (i < nb_cmds)
	{
		if (waitpid(pids[i], &g_exit_status, 0) == -1)
			continue ;
		if (WIFEXITED(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		else
			g_exit_status = 128 + WTERMSIG(g_exit_status);
		i++;
	}
}
