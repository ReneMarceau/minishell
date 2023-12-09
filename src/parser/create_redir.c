/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:32:56 by rene              #+#    #+#             */
/*   Updated: 2023/12/09 18:13:29 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "global.h"
#include "parse.h"

t_rdir	*create_redir(char *file, int type)
{
	t_rdir	*new_rdir;

	new_rdir = (t_rdir *)list_malloc(1, sizeof(t_rdir));
	if (new_rdir == NULL)
		return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
	new_rdir->value = ft_strdup(file);
	if (new_rdir->value == NULL)
		return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
	add_garbage(new_rdir->value);
	new_rdir->type = type;
	new_rdir->next = NULL;
	return (new_rdir);
}

void	add_rdir(t_cmd **head, char *file, int type)
{
	t_cmd	*current_cmd;
	t_rdir	*current_rdir;

	current_cmd = *head;
	if (current_cmd->rdir == NULL)
		current_cmd->rdir = create_redir(file, type);
	else
	{
		current_rdir = current_cmd->rdir;
		while (current_rdir->next != NULL)
			current_rdir = current_rdir->next;
		current_rdir->next = create_redir(file, type);
	}
}

void	add_arg(t_cmd **head, char *arg)
{
	t_cmd	*current;
	int		i;

	current = *head;
	i = 0;
	while (current->args[i] != NULL)
		i++;
	current->args[i] = ft_strdup(arg);
	if (current->args[i] == NULL)
		print_error(ERR_MALLOC, NULL, EXIT_FAILURE);
	add_garbage(current->args[i]);
}

bool	is_valid_token(t_token *token)
{
	if (token->type == REDIR_IN || token->type == REDIR_OUT
		|| token->type == REDIR_APPEND || token->type == HEREDOC)
	{
		if (token->next == NULL || token->next->type != STR)
			return (false);
	}
	if (token->type == PIPE)
	{
		if (token->next == NULL)
			return (false);
	}
	return (true);
}
