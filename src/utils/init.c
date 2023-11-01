/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:34:52 by rene              #+#    #+#             */
/*   Updated: 2023/10/27 14:18:06 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "global.h"

t_shell	*init_data(char **envp)
{
	t_shell	*shell;

	shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
	if (!shell)
		return (print_error(ERR_MALLOC, NULL), NULL);
	shell->cmd_table = NULL;
	shell->nb_cmd = 0;
	shell->pipe_fd[0] = NULL;
	shell->pipe_fd[1] = NULL;
	shell->input_fd = STDIN_FILENO;
	shell->output_fd = STDOUT_FILENO;
	shell->envp = envp;
	return (shell);
}

size_t	count_cmds(t_cmd *cmd_table)
{
	size_t	i;

	i = 0;
	while (cmd_table)
	{
		i++;
		cmd_table = cmd_table->next;
	}
	return (i);
}
