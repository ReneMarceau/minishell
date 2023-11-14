/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:26:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/13 11:37:53 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
/* Standard Input/Output functions, used for reading/writing to the terminal */
// printf, strerror, perror
# include <stdio.h>

/* Defines the bool type and constants */
// ----> true, false
# include <stdbool.h>

/* POSIX operating system API, provides access to various
   low-level operations like process management and file handling */
// ----> write, read, close, pipe, fork, dup, dup2, access, execve,
// ----> getcwd, chdir, unlink, isatty, ttyname, ttyslot
# include <unistd.h>

/* Various data types used in system calls */
# include <sys/types.h>

/* Functions and constants related to process control and wait operations */
// ----> wait, wait3, wait4, waitpid
# include <sys/wait.h>

/* Signal handling, used for managing process signals */
// ----> signal, sigaction, sigemptyset, sigaddset, kill
# include <signal.h>

/* File control options and functions for file I/O. */
// ----> open
# include <fcntl.h>

/* Data types, structures and functions related to the file system */
// ----> stat, lstat, fstat
# include <sys/stat.h>

/* I/O control operations, often used for terminal-related functionality */
// ----> ioctl
# include <sys/ioctl.h>

/* Functions and data types for terminal I/O,
	allowing control over terminal settings */
// ----> tcsetattr, tcgetattr
# include <termios.h>

/* Functions for Terminal-based User Interface */
// ---->  tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <curses.h>
# include <term.h>

/* Readline library for command line input handling */
// ----> readline, rl_on_new_line, rl_replace_line, rl_redisplay
# include "readline/readline.h"

/* Functionality to manage command histoy when using the Readline library */
// ----> add_history, rl_clear_history
# include "readline/history.h"

#include "env.h"

/* Libft library for custom functions */
# include "../libs/libft/inc/libft.h"

/* *************** ***************           *************** *************** */
/*                                  Macros                                   */
/* *************** ***************           *************** *************** */
# define HEREDOC_FILE "/tmp/.heredoc"

# define MAX_ARGS	100

# define READ_END	0
# define WRITE_END	1

/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */
extern int	g_exit_status;

typedef enum e_rdir_type {
	INPUT,
	OUTPUT,
	APPEND,
	HEREDOC
}	t_rdir_type;

typedef struct s_rdir {
	char			*value;
	int				type;
	struct s_rdir	*next;
}	t_rdir;

typedef struct s_cmd {
	int				index;
	char			**args;
	t_rdir			*rdir;
	pid_t			pid;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell {
	t_cmd	*cmd_table;
	int		nb_cmd;
	pid_t	*pids;
	int		**pipe_fd;
	int		input_fd;
	int		output_fd;
	t_env	*envp;
}	t_shell;

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
t_shell		*init_data(char **envp);
t_cmd    	*parsing_test(void);


#endif