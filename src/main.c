/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:03:31 by rene              #+#    #+#             */
/*   Updated: 2023/12/01 19:21:36 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"
#include "executor.h"
#include "error.h"
#include "colors.h"
#include "signals.h"

int	g_exit_status = 0;

bool	readlines(char **input, char **last_input)
{
	*input = readline(READLINE_MSG);
	if (*input == NULL)
		return (printf("exit\n"), false);
	if (*last_input == NULL)
	{
		*last_input = ft_strdup("");
		if (*last_input == NULL)
			return (print_error(ERR_MALLOC, NULL), false);
	}
	if (*input && **input && ft_strncmp(*input, *last_input, ft_strlen(*input)))
		add_history(*input);
	*last_input = ft_strdup(*input);
	if (*last_input == NULL)
		return (print_error(ERR_MALLOC, NULL), false);
	return (true);
}

void	shell_loop(t_shell *shell)
{
	char	*input;
	char	*last_input;
	char	*exit_code;

	input = NULL;
	last_input = NULL;
	while (true)
	{
		if (!readlines(&input, &last_input))
			return ;
		if (input && *input)
		{
			exit_code = ft_itoa(WEXITSTATUS(g_exit_status));
			shell->cmd_table = parsing(input, shell);
			shell->nb_cmd = count_cmds(shell->cmd_table);
			if (shell->cmd_table != NULL)
				executor(shell);
			else
				exit(0);
			// {
			// 	print_error(ERR_MALLOC, "shell");
			// 	all_free();
			// }
			
		}
		free(input);
	}
	free(last_input);
	free(exit_code);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	shell = init_data(env);
	if (shell == NULL)
		return (EXIT_FAILURE);
	sig_handle(shell);
	shell_loop(shell);
	return (EXIT_SUCCESS);
}
