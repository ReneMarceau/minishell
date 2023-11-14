/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:23 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/13 11:12:21 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "global.h"

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
int		count_cmds(t_cmd *cmd_table);
void    wait_all(pid_t *pids, int nb_cmds);
bool    close_pipes(t_shell *shell);
bool	init_pipes(t_shell *shell);
bool    init_processes(t_shell *shell);
char	**get_envp(char **env);
bool    handle_pipe_redirections(t_shell *shell,  t_cmd *cmd);
bool    executor(t_shell *shell);

#endif