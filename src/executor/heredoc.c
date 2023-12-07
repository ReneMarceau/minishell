/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:24:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/07 15:35:37 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "garbage_collector.h"
#include "executor.h"
#include "parse.h"
#include "error.h"

bool exec_heredoc(char *delimiter, int fd)
{
    char    *line;
    int     index;

    if (fd == -1)
        return (print_error(ERR_OPEN, HEREDOC_FILE, EXIT_FAILURE), false);
    index = 0;
    while (true)
    {
        line = readline("> ");
        if (line == NULL)
        {
            close(fd);
            return (print_error_heredoc("warning", index, delimiter, 1), false);
        }
        if (ft_strcmp(line, delimiter) == true)
            break ;
        ft_putendl_fd(line, fd);
        free(line);
        index++;
    }
    close(fd);
    free(line);
    g_exit_status = EXIT_SUCCESS;
    return (true);
}

bool    apply_heredoc(t_cmd **cmd, char *heredoc_file)
{
    t_rdir  *rdir;
    int    fd;

    fd = -42;
    rdir = (*cmd)->rdir;
    while (rdir != NULL)
    {
        if (rdir->type == HEREDOC && has_redirection(rdir->next, HEREDOC) == false)
        {
            fd = open(heredoc_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
            if (exec_heredoc(rdir->value, fd) == false)
                return (false);
            (*cmd)->heredoc_file = ft_strdup(heredoc_file);
            add_garbage((*cmd)->heredoc_file);
        }
        else if (rdir->type == HEREDOC)
        {
            if (exec_heredoc(rdir->value, fd) == false)
                return (false);
        }
        rdir = rdir->next;
    }
    return (true);
}

bool    create_heredoc_files(t_shell *shell)
{
    t_cmd   *cmd;
    char    *heredoc_file;
    char    *index_char;
    int     index;

    index = 1;
    cmd = shell->cmd_table;
    while (cmd != NULL)
    {
        index_char = ft_itoa(index);
        heredoc_file = ft_strjoin(HEREDOC_FILE, index_char);
        if (apply_heredoc(&cmd, heredoc_file) == false)
            return (false);
        free(index_char);
        free(heredoc_file);
        index++;
        cmd = cmd->next;
    }
    return (true);
}
