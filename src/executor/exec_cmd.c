/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:09:04 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/15 14:09:41 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include "error.h"
#include "executor.h"
#include "garbage_collector.h"
#include "global.h"

bool	exec_cmd(t_cmd *cmd, t_env *env, t_shell *shell)
{
	char	*cmd_path;
	char	**env_array;
	char	**envp;
	int		i;

	env_array = env_to_array(env);
	if (env_array == NULL || cmd->args[0] == NULL)
		return (false);
	if (cmd->args[0][0] == '/' || cmd->args[0][0] == '.')
		return (run_cmd(cmd->args[0], cmd->args, env_array, shell));
	envp = get_envp(env_array);
	if (envp == NULL)
		return (print_error(ERR_CMD_NF, cmd->args[0], EXIT_FAILURE), false);
	i = -1;
	while (envp[++i] != NULL)
	{
		cmd_path = get_cmd_fullpath(cmd->args[0], envp[i]);
		if (cmd_path == NULL)
			return (false);
		run_cmd(cmd_path, cmd->args, env_array, shell);
		free(cmd_path);
	}
	return (print_error(ERR_CMD_NF, cmd->args[0], 127), false);
}
