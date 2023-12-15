/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:08:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/15 11:19:02 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include "error.h"
#include "executor.h"
#include "garbage_collector.h"
#include "global.h"

static char	*get_cmd_fullpath(char *cmd_name, char *path)
{
	char	*cmd_path;
	char	*cmd_file;

	cmd_file = ft_strjoin("/", cmd_name);
	if (cmd_file == NULL)
		return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
	cmd_path = ft_strjoin(path, cmd_file);
	if (cmd_path == NULL)
		return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
	free(cmd_file);
	return (cmd_path);
}

static bool	run_cmd(char *path, char **args, char **envp, t_shell *shell)
{
	struct stat	st;

	if (access(path, F_OK) != -1)
	{
		if (stat(path, &st) == -1)
			return (print_error(ERR_STAT, path, EXIT_FAILURE), false);
		if (S_ISDIR(st.st_mode) && (args[0][0] == '.' || args[0][0] == '/'))
			return (print_error(ERR_ISDIR, path, 126), false);
		if (access(path, X_OK) == -1)
			return (print_error(ERR_PERM, path, 126), false);
		if (close(shell->original_stdin) == -1)
			print_error(ERR_CLOSE, NULL, EXIT_FAILURE);
		if (close(shell->original_stdout) == -1)
			print_error(ERR_CLOSE, NULL, EXIT_FAILURE);
		execve(path, args, envp);
	}
	if (args[0][0] == '.' || args[0][0] == '/')
		return (print_error(ERR_NO_SUCH_FD, path, 127), false);
	return (false);
}

bool	exec_cmd(t_cmd *cmd, t_env *env, t_shell *shell)
{
	char	*cmd_path;
	char	**env_array;
	char	**envp;
	int		i;

	env_array = env_to_array(env);
	if (env_array == NULL || cmd->args[0] == NULL)
		return (false);
	if (cmd->args[0][0] == '/' || cmd->args[0][0] == '.')
		return (run_cmd(cmd->args[0], cmd->args, env_array, shell));
	envp = get_envp(env_array);
	if (envp == NULL)
		return (print_error(ERR_CMD_NF, cmd->args[0], EXIT_FAILURE), false);
	i = -1;
	while (envp[++i] != NULL)
	{
		cmd_path = get_cmd_fullpath(cmd->args[0], envp[i]);
		if (cmd_path == NULL)
			return (false);
		run_cmd(cmd_path, cmd->args, env_array, shell);
		free(cmd_path);
	}
	return (print_error(ERR_CMD_NF, cmd->args[0], 127), false);
}

bool	apply_executor(t_shell *shell)
{
	if (redirections_operation(shell, shell->cmd_table->rdir,
			shell->cmd_table->heredoc_file) == false)
	{
		if (is_builtin(shell->cmd_table->args[0]) == true && shell->nb_cmd == 1)
			return (false);
		exit_shell(shell, true);
	}
	if (is_builtin(shell->cmd_table->args[0]) == true)
	{
		exec_builtin(shell->cmd_table, shell->envp, shell);
		if (dup2(shell->original_stdout, STDOUT_FILENO) == -1)
			return (print_error(ERR_DUP2, NULL, EXIT_FAILURE), false);
		if (dup2(shell->original_stdin, STDIN_FILENO) == -1)
			return (print_error(ERR_DUP2, NULL, EXIT_FAILURE), false);
		if (shell->nb_cmd == 1)
			return (false);
		exit_shell(shell, true);
	}
	else
	{
		if (exec_cmd(shell->cmd_table, shell->envp, shell) == false)
			exit_shell(shell, true);
	}
	return (true);
}

bool	executor(t_shell *shell)
{
	if (create_heredoc_files(shell) == false)
		return (false);
	if (init_pipes(shell) == false)
		return (false);
	if (init_processes(shell) == false)
		return (false);
	while (shell->cmd_table != NULL)
	{
		if (shell->cmd_table->pid == 0)
		{
			set_to_process(shell);
			if (apply_executor(shell) == false)
				return (false);
		}
		shell->cmd_table = shell->cmd_table->next;
	}
	close_pipes(shell);
	wait_all(shell->pids, shell->nb_cmd);
	return (true);
}
