/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:08:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/29 22:30:27 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "garbage_collector.h"
#include "builtin.h"
#include "executor.h"
#include "env.h"
#include "error.h"

static char *get_cmd_fullpath(char *cmd_name, char *path)
{
    char    *cmd_path;
    char    *cmd_file;

    cmd_file = ft_strjoin("/", cmd_name);
    if (cmd_file == NULL)
        return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
    cmd_path = ft_strjoin(path, cmd_file);
    if (cmd_path == NULL)
        return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
    free(cmd_file);
    return (cmd_path);
}

static bool run_cmd(char *path, char **args, char **envp, bool print_err)
{
    struct stat st;
    
    if (access(path, F_OK) != -1)
    {
        if (stat(path, &st) == -1)
            return (print_error(ERR_STAT, path, EXIT_FAILURE), false);
        if (S_ISDIR(st.st_mode))
            return (print_error(ERR_ISDIR, path, 126), false);
        if (access(path, X_OK) == -1)
            return (print_error(ERR_PERM, path, 126), false);
        execve(path, args, envp);
    }
    if (print_err == true)
        return (print_error(ERR_NO_SUCH_FD, path, 127), false);
    return (false);
}    

bool    exec_cmd(t_cmd *cmd, t_env *env)
{
    char    *cmd_path;
    char    **env_array;
    char    **envp;
    int     i;

    env_array = env_to_array(env);
    if (env_array == NULL || cmd->args[0] == NULL)
        return (false);
    if (cmd->args[0][0] == '/' || cmd->args[0][0] == '.')
        return(run_cmd(cmd->args[0], cmd->args, env_array, true));
    envp = get_envp(env_array);
    if (envp == NULL)
        return (print_error(ERR_CMD_NF, cmd->args[0], EXIT_FAILURE), false);
    add_garbage(envp);
    i = -1;
    while (envp[++i] != NULL)
    {
        cmd_path = get_cmd_fullpath(cmd->args[0], envp[i]);
        if (cmd_path == NULL)
            return (false);
        run_cmd(cmd_path, cmd->args, env_array, false);
        free(cmd_path);
    }
    return (print_error(ERR_CMD_NF, cmd->args[0], 127), false);
}

static bool    redirections_operation(t_shell *shell, t_rdir *rdir, char *heredoc_file)
{
    while (rdir != NULL)
    {
        if (handle_redirections(shell, rdir, heredoc_file) == false)
            return (false);
        rdir = rdir->next;
    }
    if (handle_pipe_redirections(shell, shell->cmd_table) == false)
        return (false);
    close_pipes(shell);
    return (true);
}

bool    executor(t_shell *shell)
{
    int original_stdout = dup(STDOUT_FILENO);
    int original_stdin = dup(STDIN_FILENO);
    
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
            if (redirections_operation(shell, shell->cmd_table->rdir, shell->cmd_table->heredoc_file) == false)
            {
                if (is_builtin(shell->cmd_table->args[0]) == true)
                {
                    if (shell->nb_cmd == 1)
                        return (false);
                }
                exit(g_exit_status);
            }
            if (is_builtin(shell->cmd_table->args[0]) == true)
            {
                exec_builtin(shell->cmd_table, shell->envp);
                if (dup2(original_stdout, STDOUT_FILENO) == -1)
                    return (print_error(ERR_DUP2, NULL, EXIT_FAILURE), false);
                if (dup2(original_stdin, STDIN_FILENO) == -1)
                    return (print_error(ERR_DUP2, NULL, EXIT_FAILURE), false);

                if (shell->nb_cmd == 1)
                    return (true);
                exit(g_exit_status);
            }
            else
            {
                if (exec_cmd(shell->cmd_table, shell->envp) == false)
                    exit(g_exit_status);
            }
        }
        shell->cmd_table = shell->cmd_table->next;
    }
    close_pipes(shell);
    wait_all(shell->pids, shell->nb_cmd);
    return (true);
}
