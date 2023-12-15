/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:54:45 by rene              #+#    #+#             */
/*   Updated: 2023/12/15 10:50:26 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "global.h"
#include "parse.h"

bool	handle_syntax_error(t_token *token_list)
{
	if (is_valid_token(token_list) == false)
	{
		if (token_list->type != PIPE)
		{
			if (token_list->next == NULL)
				return (print_error_syntax(ERR_SYNTAX, "newline", 2), false);
			else
				return (print_error_syntax(ERR_SYNTAX, token_list->next->token,
						2), false);
		}
		return (print_error_syntax(ERR_SYNTAX, token_list->token, 2), false);
	}
	return (true);
}

bool	handle_open_failed(int fd, char *file)
{
	if (fd == -1)
	{
		if (errno == ENOENT)
			return (print_error(ERR_NO_SUCH_FD, file, EXIT_FAILURE), false);
		else if (errno == EISDIR)
			return (print_error(ERR_ISDIR, file, EXIT_FAILURE), false);
		else
			return (print_error(ERR_PERM, file, EXIT_FAILURE), false);
	}
	return (true);
}
