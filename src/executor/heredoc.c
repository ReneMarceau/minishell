/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:24:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/15 13:25:07 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "executor.h"
#include "garbage_collector.h"
#include "global.h"
#include "parse.h"

bool	exec_heredoc(t_shell *shell, char *delimiter, int fd, int index)
{
	char	*line;
	bool	quote;
	
	if (fd == -1)
		return (print_error(ERR_OPEN, HEREDOC_FILE, EXIT_FAILURE), false);
	quote = delimit_quote(shell, delimiter);
	delimiter = rm_quote_str_here(delimiter, shell);
	while (true)
	{
		line = readline("> ");
		if (sig_state(false)->type == SIG_HEREDOC)
            return ((void)close(fd), free(line), set_to_inter(shell), false);
		if (line == NULL)
			return ((void)close(fd), print_error_heredoc("warning", index,
					delimiter, 1), false);
		line = change_for_quote(shell, line, quote);
		if (ft_strcmp(line, delimiter) == true)
			break ;
		ft_putendl_fd(line, fd);
		index++;
	}
	return (leave_here(fd, line), true);
}

bool	apply_heredoc(t_shell *shell, t_cmd **cmd, char *heredoc_file)
{
	t_rdir	*rdir;
	int		fd;

	fd = -42;
	rdir = (*cmd)->rdir;
	while (rdir != NULL)
	{
		if (rdir->type == HEREDOC && has_redirection(rdir->next,
				HEREDOC) == false)
		{
			fd = open(heredoc_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (exec_heredoc(shell, rdir->value, fd, 0) == false)
				return (false);
			(*cmd)->heredoc_file = ft_strdup(heredoc_file);
			add_garbage((*cmd)->heredoc_file);
		}
		else if (rdir->type == HEREDOC)
		{
			if (exec_heredoc(shell, rdir->value, fd, 0) == false)
				return (false);
		}
		rdir = rdir->next;
	}
	return (true);
}

bool	create_heredoc_files(t_shell *shell)
{
	t_cmd	*cmd;
	char	*heredoc_file;
	char	*index_char;
	int		index;

	index = 1;
	cmd = shell->cmd_table;
	while (cmd != NULL)
	{
		index_char = ft_itoa(index);
		heredoc_file = ft_strjoin(HEREDOC_FILE, index_char);
		if (apply_heredoc(shell, &cmd, heredoc_file) == false)
			return (free(heredoc_file), free(index_char), false);
		free(index_char);
		free(heredoc_file);
		index++;
		cmd = cmd->next;
	}
	return (true);
}
