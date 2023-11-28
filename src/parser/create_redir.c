/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:32:56 by rene              #+#    #+#             */
/*   Updated: 2023/11/28 15:45:54 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "parse.h"

t_rdir  *create_redir(char *file, int type)
{
    t_rdir  *new_rdir;

    new_rdir = (t_rdir *)list_malloc(1, sizeof(t_rdir));
    if (new_rdir == NULL)
        return (exit_shell(ERR_MALLOC), NULL);
    new_rdir->value = ft_strdup(file);
    
    if (new_rdir->value == NULL)
        return (exit_shell(ERR_MALLOC), NULL);
    new_rdir->type = type;
    new_rdir->next = NULL;
    return (new_rdir);
}

void    add_rdir(t_cmd **head, char *file, int type)
{
    t_cmd   *current_cmd;
    t_rdir  *current_rdir;

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

void    add_arg(t_cmd **head, char *arg)
{
    t_cmd   *current;
    int     i;

    current = *head;
    i = 0;
    if (current->args == NULL)
        printf("args is NULL\n");
    while (current->args[i] != NULL)
        i++;
    current->args[i] = ft_strdup(arg);
}

bool    is_valid_token(t_token *token)
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
