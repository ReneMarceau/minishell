/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:24:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/16 14:25:13 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "executor.h"
#include "parse.h"
#include "error.h"

bool exec_heredoc(char *delimiter, int fd)
{
    char    *line;

    if (fd == -1)
        return (print_error(ERR_OPEN, HEREDOC_FILE), false);
    while (true)
    {
        line = readline("> ");
        if (ft_strncmp(line, delimiter, ft_strlen(line)) == 0)
        {
            free(line);
            break ;
        }
        ft_putendl_fd(line, fd);
        free(line);
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
        heredoc_file = ft_strjoin(HEREDOC_FILE, index_char);
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
