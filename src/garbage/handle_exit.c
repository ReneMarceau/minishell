/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:21:45 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/07 14:11:46 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "global.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env != NULL)
	{
		tmp = env;
		env = env->next;
		if (tmp->key != NULL)
			free(tmp->key);
		if (tmp->value != NULL)
			free(tmp->value);
		free(tmp);
	}
}

void	exit_shell(t_shell *shell, bool is_exit)
{
	if (close(shell->original_stdin) == -1)
		print_error(ERR_CLOSE, NULL, EXIT_FAILURE);
	if (close(shell->original_stdout) == -1)
		print_error(ERR_CLOSE, NULL, EXIT_FAILURE);
	all_free();
	if (shell->last_input != NULL)
		free(shell->last_input);
	if (shell->envp != NULL)
		free_env(shell->envp);
	if (shell != NULL)
		free(shell);
	if (is_exit == true)
		exit(g_exit_status);
}
