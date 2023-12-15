/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:25 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/15 00:21:39 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "executor.h"
#include "garbage_collector.h"
#include "global.h"
#include "parse.h"

bool delimit_quote(t_shell *shell, char *delimiter)
{
	set_to_heredoc(shell);
	if (is_there_quote(delimiter) == true)
	{
		// rm_quote_str(delimiter, shell);
		return (TRUE);
	}
	return (FALSE);
}

char *new_read(void)
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

char *change_for_quote(t_shell *shell, char *line, bool quote)
{
	if (!quote)
		line = get_expand(line, shell);
	return (line);
}

void leave_here(int fd, char *line)
{
	(void)line;
	close (fd);
	// free (line); 
	g_exit_status = EXIT_SUCCESS;
}
