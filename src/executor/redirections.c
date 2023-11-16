/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:05:48 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/16 16:00:57 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"
#include "executor.h"
#include "error.h"

bool    has_redirection(t_rdir *rdir, int type)
{
    while (rdir != NULL)
    {
        if (rdir->type == type)
            return (true);
        rdir = rdir->next;
    }
    return (false);
}

static bool handle_input_redirection(t_shell *shell, t_rdir *rdir, char *heredoc_file)
{
    if (rdir->type == HEREDOC)
    {
        if (has_redirection(rdir->next, HEREDOC) == true)
            return (true);
        shell->input_fd = open(heredoc_file, O_RDONLY);
        if (shell->input_fd == -1)
            return (print_error(ERR_OPEN, heredoc_file), false);
        if (dup2(shell->input_fd, STDIN_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
        if (close(shell->input_fd) == -1)
            return (print_error(ERR_CLOSE, NULL), false);
        if (unlink(heredoc_file) == -1)
            return (print_error(ERR_UNLINK, heredoc_file), false);
    }
    else
    {
        if (has_redirection(rdir->next, REDIR_IN) == true)
            return (true);
        shell->input_fd = open(rdir->value, O_RDONLY);
        if (shell->input_fd == -1)
            return (print_error(ERR_OPEN, rdir->value), false);
        if (dup2(shell->input_fd, STDIN_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
        if (close(shell->input_fd) == -1)
            return (print_error(ERR_CLOSE, NULL), false);
    }
    return (true);
}

static bool handle_output_redirection(t_shell *shell, t_rdir *rdir)
{
    if (rdir->type == REDIR_OUT)
    {
        if (has_redirection(rdir->next, REDIR_OUT) == true)
            return (true);
        shell->output_fd = open(rdir->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (shell->output_fd == -1)
            return (print_error(ERR_OPEN, rdir->value), false);
        if (dup2(shell->output_fd, STDOUT_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
        if (close(shell->output_fd) == -1)
            return (print_error(ERR_CLOSE, NULL), false);
    }
    else if (rdir->type == REDIR_APPEND)
    {
        if (has_redirection(rdir->next, REDIR_APPEND) == true)
            return (true);
        shell->output_fd = open(rdir->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (shell->output_fd == -1)
            return (print_error(ERR_OPEN, rdir->value), false);
        if (dup2(shell->output_fd, STDOUT_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
        if (close(shell->output_fd) == -1)
            return (print_error(ERR_CLOSE, NULL), false);
    }
    return (true);
}

bool    handle_redirections(t_shell *shell, t_rdir *rdir, char *heredoc_file)
{
    if (rdir->type == REDIR_IN || rdir->type == HEREDOC)
    {
        if (handle_input_redirection(shell, rdir, heredoc_file) == false)
            return (false);
    }
    else if (rdir->type == REDIR_OUT || rdir->type == REDIR_APPEND)
    {
        if (handle_output_redirection(shell, rdir) == false)
            return (false);
    }
    else
    {
        if (dup2(shell->output_fd, STDOUT_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
    }
    return (true);
}

bool    handle_pipe_redirections(t_shell *shell,  t_cmd *cmd)
{
    if (cmd->index > 0 && has_redirection(cmd->rdir, REDIR_IN) == false && has_redirection(cmd->rdir, HEREDOC) == false)
    {
        if (dup2(shell->pipe_fd[cmd->index - 1][READ_END], STDIN_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
    }
    if (cmd->next != NULL && has_redirection(cmd->rdir, REDIR_OUT) == false && has_redirection(cmd->rdir, REDIR_APPEND) == false)
    {
        if (dup2(shell->pipe_fd[cmd->index][WRITE_END], STDOUT_FILENO) == -1)
            return (print_error(ERR_DUP2, NULL), false);
    }
    return (true);
}
