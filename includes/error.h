/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:24:00 by rene              #+#    #+#             */
/*   Updated: 2023/11/20 15:29:12 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
/* Standard Library functions, provides memory allocation and other functions */
// ----> malloc, free, exit, getenv
# include <stdlib.h>
# include <errno.h>

/* *************** ***************           *************** *************** */
/*                                  Macros                                   */
/* *************** ***************           *************** *************** */
// Minishell Tag
# define TAG				"minishell: "

// Memory Allocation Errors
# define ERR_MALLOC			"Out of memory"

// Command Execution Errors
# define ERR_CMD_NF			"command not found"
# define ERR_CMD_NOT_EXEC	"command not executable"
# define ERR_TOO_MANY_ARGS	"too many arguments"
# define ERR_NUMERIC_ARG	"numeric argument required"
# define ERR_INVALID_OPT	"invalid option"
# define ERR_INVALID_ID		"not a valid identifier"

// Variable and String Errors
# define ERR_VAR_NOT_SET	"Variable not set"
# define ERR_UNTERM_STR		"unterminated quoted string"

// Process and System Errors
# define ERR_JOB_CONTROL	"Job control not active"
# define ERR_BAD_FD			"Bad file descriptor"
# define ERR_CMD_INT		"Command interrupted"
# define ERR_NUM_ARG_REQ	"Numeric argument required"
# define ERR_FORK			"Child process creation failed"
# define ERR_PIPE			"pipe failed"
# define ERR_DUP2			"dup2 failed"
# define ERR_UNLINK			"failed to remove file"

// File Handling Errors
# define ERR_NO_SUCH_FD		"No such file or directory"
# define ERR_ISDIR			"Is a directory"
# define ERR_NODIR			"Not a directory"
# define ERR_PERM			"Permission denied"
# define ERR_CLOSE			"closing file failed"
# define ERR_OPEN			"opening file failed"

// Syntax and Parsing Errors
# define ERR_SYNTAX			"syntax error near unexpected token"
# define ERR_AMBREDIR		"ambiguous redirect"

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
void	print_error(char *error_message, char *arg);
void	print_error_builtin(char *error_message, char *cmd_name, char *option);

#endif