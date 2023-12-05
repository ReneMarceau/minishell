/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:33:33 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/05 10:24:50 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
# include <stdbool.h>

# include "env.h"

/* *************** ***************           *************** *************** */
/*                                  Macros                                   */
/* *************** ***************           *************** *************** */

/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
char    *get_env_value(t_env *env, char *key);
void    set_env_value(t_env *env, char *key, char *value);
bool    is_builtin(char *cmd_name);
bool    exec_echo(t_cmd *cmd);
bool    exec_cd(t_cmd *cmd, t_env *env);
bool    exec_env(t_cmd *cmd, t_env *env);
bool    exec_pwd(t_cmd *cmd);
bool    exec_export(t_cmd *cmd, t_env *env);
bool    exec_unset(t_cmd *cmd, t_env *env);
bool    exec_exit(t_cmd *cmd);
bool    exec_builtin(t_cmd *cmd, t_env *env);

#endif