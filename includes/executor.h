/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:23 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/15 14:10:03 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "global.h"

/* File control options and functions for file I/O. */
// ----> open
# include <fcntl.h>

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
int		count_cmds(t_cmd *cmd_table);
void	wait_all(pid_t *pids, int nb_cmds);
bool	close_pipes(t_shell *shell);
bool	init_pipes(t_shell *shell);
bool	init_processes(t_shell *shell);
char	**get_envp(char **env);
bool	exec_cmd(t_cmd *cmd, t_env *env, t_shell *shell);
//heredoc_utils ----------------
bool	delimit_quote(t_shell *shell, char *delimiter);
char	*new_read(void);
char	*change_for_quote(t_shell *shell, char *line, bool quote);
void	leave_here(int fd, char *line);
bool	create_heredoc_files(t_shell *shell);
bool	exec_heredoc(t_shell *shell, char *delimiter, int fd, int index);
bool	has_redirection(t_rdir *rdir, int type);
bool	handle_redirections(t_shell *shell, t_rdir *rdir, char *heredoc_file);
bool	handle_pipe_redirections(t_shell *shell, t_cmd *cmd);
bool	executor(t_shell *shell);

#endif