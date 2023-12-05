/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:10:48 by rene              #+#    #+#             */
/*   Updated: 2023/12/05 11:10:32 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "colors.h"

void	print_error(char *error_message, char *arg, int exit_status)
{
	ft_putstr_fd(TAG, STDERR_FILENO);
	if (arg)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(error_message, STDERR_FILENO);
	g_exit_status = exit_status;
}

void	print_error_builtin(char *error_message, char *cmd_name, char *option, int exit_status)
{
	ft_putstr_fd(TAG, STDERR_FILENO);
	if (cmd_name)
	{
		ft_putstr_fd(cmd_name, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (option)
	{
		ft_putstr_fd(option, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(error_message, STDERR_FILENO);
	g_exit_status = exit_status;
}

void	print_error_syntax(char *error_message, char *token, int exit_status)
{
	ft_putstr_fd(TAG, STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
	if (token)
	{
		ft_putstr_fd(" `", STDERR_FILENO);
		ft_putstr_fd(token, STDERR_FILENO);
		ft_putstr_fd("'", STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	g_exit_status = exit_status;
}

void	print_error_heredoc(char *args, int line, char *delimiter, int exit_status)
{
	char *line_str;

	line_str = ft_itoa(++line);
	ft_putstr_fd(TAG, STDERR_FILENO);
	if (args)
	{
		ft_putstr_fd(args, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd("here-document at line ", STDERR_FILENO);
	ft_putstr_fd(line_str, STDERR_FILENO);
	ft_putstr_fd(" delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delimiter, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
	free(line_str);
	g_exit_status = exit_status;		
}
