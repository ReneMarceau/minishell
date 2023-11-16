/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:08:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/15 22:08:51 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "executor.h"
#include "env.h"
#include "error.h"

static char *get_cmd_fullpath(char *cmd_name, char *path)
{
    char    *cmd_path;
    char    *cmd_file;

    cmd_file = ft_strjoin("/", cmd_name);
    if (cmd_file == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    cmd_path = ft_strjoin(path, cmd_file);
    if (cmd_path == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    free(cmd_file);
    return (cmd_path);
}

static bool run_cmd(char *path, char **args, char **envp, bool print_err)
{
    if (access(path, F_OK | X_OK) != -1)
        execve(path, args, envp);
    if (print_err == true)
        return (print_error(ERR_CMD_NF, path), false);
    return (false);
}    

bool    exec_cmd(t_cmd *cmd, t_env *env)
{
    char    *cmd_path;
    char    **env_array;
    char    **envp;
    int     i;

    env_array = env_to_array(env);
    if (env_array == NULL)
        return (false);
    if (cmd->args[0][0] == '/' || cmd->args[0][0] == '.')
        return(run_cmd(cmd->args[0], cmd->args, env_array, true));
    envp = get_envp(env_array);
    if (envp == NULL)
        return (print_error(ERR_VAR_NOT_SET, "PATH"), false);
    i = -1;
    while (envp[++i])
    {
        cmd_path = get_cmd_fullpath(cmd->args[0], envp[i]);
        if (cmd_path == NULL)
            return (false);
        run_cmd(cmd_path, cmd->args, env_array, false);
    }
    return (print_error(ERR_CMD_NF, cmd->args[0]), false);
}

bool    redirections_operation(t_shell *shell, t_rdir *rdir)
{
    while (rdir != NULL)
    {
        if (handle_redirections(shell, rdir) == false)
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
    if (init_pipes(shell) == false)
        return (false);
    if (init_processes(shell) == false)
        return (false);
    while (shell->cmd_table != NULL)
    {
        if (shell->cmd_table->pid == 0)
        {
            if (redirections_operation(shell, shell->cmd_table->rdir) == false)
                exit(g_exit_status);
            if (exec_cmd(shell->cmd_table, shell->envp) == false)
                exit(g_exit_status);
        }
        shell->cmd_table = shell->cmd_table->next;
    }
    close_pipes(shell);
    wait_all(shell->pids, shell->nb_cmd);
    return (true);
}
