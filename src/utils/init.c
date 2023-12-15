/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:34:52 by rene              #+#    #+#             */
/*   Updated: 2023/12/07 13:46:26 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "garbage_collector.h"
#include "builtin.h"
#include "env.h"
#include "error.h"

t_shell	*init_data(char **envp)
{
	t_shell	*shell;
	
	shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
	if (shell == NULL)
		return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
	shell->cmd_table = NULL;
	shell->nb_cmd = 0;
	shell->pids = NULL;
	shell->pipe_fd = NULL;
	shell->last_input = NULL;
	shell->input_fd = STDIN_FILENO;
	shell->output_fd = STDOUT_FILENO;
	shell->original_stdin = dup(STDIN_FILENO);
	shell->original_stdout = dup(STDOUT_FILENO);
	shell->envp = build_env_list(envp);
	if (shell->envp == NULL)
		return (NULL);
	return (shell);
}

int	count_cmds(t_cmd *cmd_table)
{
	int	count;

	count = 0;
	while (cmd_table != NULL)
	{
		count++;
		cmd_table = cmd_table->next;
	}
	return (count);
}

char	**get_envp(char **env)
{
	char	**enviroment;
	char	*path_trimmed;
	int		i;

	enviroment = NULL;
	path_trimmed = NULL;
	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			path_trimmed = ft_strtrim(env[i], "PATH=");
			if (path_trimmed == NULL)
				return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
			enviroment = ft_split(path_trimmed, ':');
			if (enviroment == NULL)
				return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
			break ;
		}
	}
	if (path_trimmed != NULL)
		free(path_trimmed);
	return (enviroment);
}
