/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:30:03 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/15 10:45:49 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include "error.h"
#include "global.h"

bool	change_directory(char *path, char *path_name, t_env *env)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (get_env_value(env, path_name) == NULL)
	{
		if (ft_strcmp(path_name, "HOME") == true)
			return (print_error_builtin("HOME not set", "cd", NULL, 1),
				free(pwd), false);
		else if (ft_strcmp(path_name, "OLDPWD") == true)
			return (print_error_builtin("OLDPWD not set", "cd", NULL, 1),
				free(pwd), false);
	}
	if (chdir(path) == -1)
		return (print_error_builtin(strerror(errno), "cd", path, 1), free(pwd),
			false);
	set_env_value(env, "OLDPWD", pwd);
	free(pwd);
	pwd = getcwd(NULL, 0);
	set_env_value(env, "PWD", pwd);
	free(pwd);
	return (true);
}

bool	apply_cd(t_cmd *cmd, t_env *env)
{
	char	*path;

	if (cmd->args[1] == NULL)
	{
		if (change_directory(get_env_value(env, "HOME"), "HOME", env) == false)
			return (false);
	}
	else if (cmd->args[1][0] == '~')
	{
		path = ft_strjoin(get_env_value(env, "HOME"), cmd->args[1] + 1);
		if (change_directory(path, "HOME", env) == false)
			return (free(path), false);
		free(path);
	}
	else if (ft_strcmp(cmd->args[1], "-") == true)
	{
		if (change_directory(get_env_value(env, "OLDPWD"), "OLDPWD",
				env) == false)
			return (false);
		printf("%s\n", get_env_value(env, "OLDPWD"));
	}
	else
		return (change_directory(cmd->args[1], cmd->args[1], env));
	return (true);
}

bool	exec_cd(t_cmd *cmd, t_env *env)
{
	if (cmd->args[1] != NULL && cmd->args[1][0] == '-'
		&& cmd->args[1][1] != '\0')
		return (print_error_builtin(ERR_INVALID_OPT, cmd->args[0], cmd->args[1],
				2), false);
	if (apply_cd(cmd, env) == false)
		return (false);
	g_exit_status = EXIT_SUCCESS;
	return (true);
}
