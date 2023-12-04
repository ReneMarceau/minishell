/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:21:45 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/03 18:40:52 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env != NULL)
	{
		tmp = env;
		env = env->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}

void exit_shell(t_shell *shell, bool is_exit)
{
	all_free();
	if (shell->envp != NULL)
		free_env(shell->envp);
	if (shell != NULL)
		free(shell);
	if (is_exit == true)
		exit(g_exit_status);
}
