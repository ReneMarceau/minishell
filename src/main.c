/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:03:31 by rene              #+#    #+#             */
/*   Updated: 2023/10/26 22:11:31 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "colors.h"

int g_exit_code = 0;

bool	readlines(char **input, char **last_input) {
	*input = readline(READLINE_MSG);
	if (*input == NULL)
		return (print_error(ERR_MALLOC, NULL), false);
	if (*last_input == NULL) {
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

void	shell_loop(t_shell *shell) {
	char	*input;
	char	*last_input;
	char	*exit_code;

	input = NULL;
	last_input = NULL;
	while (true) {
		if (!readlines(&input, &last_input))
			break ;
		if (input && *input) {
			exit_code = ft_itoa(WEXITSTATUS(g_exit_code));
			(void)shell;
		}
		free(input);
	}
	free(last_input);
	free(exit_code);
}

int main(int argc, char **argv, char **env) {
	t_shell *shell;
	(void)argc;
	(void)argv;

	shell = init_data(env);
	shell_loop(shell);
	return (EXIT_SUCCESS);
}