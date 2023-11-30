/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:24:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/29 23:24:08 by rene             ###   ########.fr       */
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
            if (line != NULL)
                free(line);
            if (close(fd) == -1)
                return (print_error(ERR_CLOSE, HEREDOC_FILE, EXIT_FAILURE), false);
            return (print_error_heredoc("warning", index, delimiter, EXIT_FAILURE), false);
        }
        if (ft_strcmp(line, delimiter) == true)
        {
            free(line);
            break ;
        }
        ft_putendl_fd(line, fd);
        free(line);
        index++;
    }
    close(fd);
    return (true);
}

bool    create_heredoc_files(t_shell *shell)
{
    t_cmd   *cmd;
    t_rdir  *rdir;
    char    *heredoc_file;
    char    *index_char;
    int     index;
    int     fd;

    index = 1;
    cmd = shell->cmd_table;
    while (cmd != NULL)
    {
        index_char = ft_itoa(index);
        if (index_char == NULL)
            return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), false);
        heredoc_file = ft_strjoin(HEREDOC_FILE, index_char);
        if (heredoc_file == NULL)
            return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), false);
        rdir = cmd->rdir;
        while (rdir != NULL)
        {
            fd = -42;
            if (rdir->type == HEREDOC && has_redirection(rdir->next, HEREDOC) == false)
            {
                fd = open(heredoc_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
                if (exec_heredoc(rdir->value, fd) == false)
                    return (false);
                cmd->heredoc_file = ft_strdup(heredoc_file);
                if (cmd->heredoc_file == NULL)
                    exit_shell(ERR_MALLOC, EXIT_FAILURE);
                add_garbage(cmd->heredoc_file);

            }
            else if (rdir->type == HEREDOC)
            {
                if (exec_heredoc(rdir->value, fd) == false)
                    return (false);
            }
            rdir = rdir->next;
        }
        free(index_char);
        free(heredoc_file);
        index++;
        cmd = cmd->next;
    }
    return (true);
}
