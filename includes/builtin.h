/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:33:33 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/14 15:40:50 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
# include "env.h"
# include "global.h"
# include <stdbool.h>

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
char	*get_env_value(t_env *env, char *key);
void	set_env_value(t_env *env, char *key, char *value);
bool	is_valid_identifier(char **args);
bool	is_builtin(char *cmd_name);
bool	exec_echo(t_cmd *cmd);
bool	exec_cd(t_cmd *cmd, t_env *env);
bool	exec_env(t_cmd *cmd, t_env *env);
bool	exec_pwd(t_cmd *cmd);
bool	exec_export(t_cmd *cmd, t_env *env);
bool	exec_unset(t_cmd *cmd, t_env *env);
bool	exec_exit(t_shell *shell, t_cmd *cmd);
bool	exec_builtin(t_cmd *cmd, t_env *env, t_shell *shell);

#endif