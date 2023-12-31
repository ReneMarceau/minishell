/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:25 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/15 14:35:54 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "executor.h"
#include "garbage_collector.h"
#include "global.h"
#include "parse.h"

bool	delimit_quote(t_shell *shell, char *delimiter)
{
	set_to_heredoc(shell);
	if (is_there_quote(delimiter) == true)
	{
		return (TRUE);
	}
	return (FALSE);
}

// char *new_read(void)
// {
// 	char *line;
// 	char *nl;

// 	line = readline("> ");
// 	if (line == NULL)
// 		return (NULL);
// 	nl = ft_strdup(line);
// 	if (nl == NULL)
// 		return (NULL);
// 	return (free(line), nl);
// }

char	*change_for_quote(t_shell *shell, char *line, bool quote)
{
	if (!quote)
		line = get_expand(line, shell);
	return (line);
}

void	leave_here(int fd, char *line)
{
	(void)line;
	close(fd);
	free(line);
	g_exit_status = EXIT_SUCCESS;
}
