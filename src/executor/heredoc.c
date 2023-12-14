/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:24:17 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/13 23:11:15 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "executor.h"
#include "garbage_collector.h"
#include "global.h"
#include "parse.h"

static bool init_heredoc(t_shell *shell, char *delimiter)
{
	set_to_heredoc(shell);
	if (is_there_quote(delimiter) == true)
		rm_quote_str(delimiter, shell);
	else
		delimiter = get_expand(delimiter, shell);
	if (shell->mem_err_flg == TRUE)
		return (FALSE);
	return (TRUE);
}

static char *new_read(void)
{
	char *line;
	char *nl;
	
	line = readline("> ");
	if (line == NULL)
		return (NULL);
	nl = ft_strdup(line);
	if (nl == NULL)
		return (free(line), NULL);
	return (free(line), nl);
}

static char *change_for_quote(t_shell *shell, char *delimiter, char *line)
{
	char * new_line;
	
	new_line = NULL;
	new_line = list_malloc(1, sizeof(char*));
	if (is_there_quote(delimiter) == false)
		new_line = get_expand(line, shell);
	return (new_line);
}

bool	exec_heredoc(t_shell *shell, char *delimiter, int fd)
{
	char	*line;
	int		index;

	if (fd == -1)
		return (print_error(ERR_OPEN, HEREDOC_FILE, EXIT_FAILURE), false);
	if (!init_heredoc(shell, delimiter))
		return (print_error(ERR_MALLOC, HEREDOC_FILE, EXIT_FAILURE), false);
	index = 0;
	while (true)
	{
		line = new_read();
		if (sig_state(false)->type == SIG_HEREDOC)
            return ((void)close(fd), free(line), set_to_inter(shell), false);
		if (line == NULL)
			return ((void)close(fd), print_error_heredoc("warning", index,
					delimiter, 1), false);
		line = change_for_quote(shell, delimiter, line);
		if (ft_strcmp(line, delimiter) == true)
			break ;
		ft_putendl_fd(line, fd);
		// free(line);
		index++;
	}
	g_exit_status = EXIT_SUCCESS;
	return ((void)close(fd), free(line), true);
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
			if (exec_heredoc(shell, rdir->value, fd) == false)
				return (false);
			(*cmd)->heredoc_file = ft_strdup(heredoc_file);
			add_garbage((*cmd)->heredoc_file);
		}
		else if (rdir->type == HEREDOC)
		{
			if (exec_heredoc(shell, rdir->value, fd) == false)
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
