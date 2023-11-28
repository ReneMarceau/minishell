/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:03:31 by rene              #+#    #+#             */
/*   Updated: 2023/11/28 14:40:51 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"
#include "executor.h"
#include "error.h"
#include "colors.h"

int	g_exit_status = 0;

bool	readlines(char **input, char **last_input)
{
	*input = readline(READLINE_MSG);
	if (*input == NULL)
		return (exit_shell("exit"), false);
	if (*last_input == NULL)
	{
		*last_input = ft_strdup("");
		if (*last_input == NULL)
			return (print_error(ERR_MALLOC, NULL), false);
	}
	if (*input && **input && ft_strncmp(*input, *last_input, ft_strlen(*input)))
		add_history(*input);
	free(*last_input);
	*last_input = ft_strdup(*input);
	if (*last_input == NULL)
		return (print_error(ERR_MALLOC, NULL), false);
	return (true);
}

void	shell_loop(t_shell *shell)
{
	char	*input;
	char	*last_input;

	input = NULL;
	last_input = NULL;
	while (true)
	{
		if (!readlines(&input, &last_input))
			return ;
		if (input && *input)
		{
			shell->cmd_table = parsing(input, shell);
			shell->nb_cmd = count_cmds(shell->cmd_table);
			if (shell->cmd_table != NULL) 
				executor(shell);
			all_free();
		}
		free(input);
	}
	free(last_input);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	shell = init_data(env);
	if (shell == NULL)
		return (EXIT_FAILURE);
	//signalhandler();
	shell_loop(shell);
	free(shell);
	return (EXIT_SUCCESS);
}
