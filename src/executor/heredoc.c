/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:24:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/15 15:36:07 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"

bool exec_heredoc(char *delimiter)
{
    int    fd;
    char    *line;

    fd = open(HEREDOC_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (print_error(ERR_OPEN, HEREDOC_FILE), false);
    while (true)
    {
        line = readline("> ");
        if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
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
