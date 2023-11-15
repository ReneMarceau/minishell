/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:30:51 by rene              #+#    #+#             */
/*   Updated: 2023/11/15 00:52:43 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"

static t_cmd    *create_cmd(int index)
{
    t_cmd   *new_cmd;

    new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
    if (new_cmd == NULL)
        return (NULL);
    new_cmd->index = index;
    new_cmd->args = (char **)ft_calloc(MAX_ARG, sizeof(char *));
    if (new_cmd->args == NULL)
        return (NULL);
    new_cmd->rdir = NULL;
    new_cmd->pid = 69;
    new_cmd->next = NULL;
    return (new_cmd);
}

void    add_cmd(t_cmd **head, t_cmd *new_cmd)
{
    t_cmd   *current;

    current = *head;
    if (*head == NULL)
        *head = new_cmd;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new_cmd;
    }
}

static int count_cmd(t_token *head)
{
    t_token *current;
    int count;

    count = 0;
    current = head;
    while (current != NULL)
    {
        if (current->type == PIPE)
            count++;
        current = current->next;
    }
    return (count + 1);
}

void    fill_empty_cmd_table(t_cmd **cmd_table, int cmd_count)
{
    int     index;

    index = 0;
    while (index < cmd_count)
    {
        if (index == 0)
            *cmd_table = create_cmd(index);
        else
            add_cmd(cmd_table, create_cmd(index));
        index++;
    }
}

t_cmd   *fill_cmd_table(t_token *token_list)
{
    t_cmd   **cmd_table = NULL;
    t_cmd   *current_cmd;
    
    cmd_table = (t_cmd **)malloc(sizeof(t_cmd *));
    if (cmd_table == NULL)
        return (NULL);
    fill_empty_cmd_table(cmd_table, count_cmd(token_list));
    current_cmd = *cmd_table;
    while (token_list != NULL)
    {
        if (token_list->type == PIPE)
            current_cmd = current_cmd->next;
        else if (token_list->type == STR)
            add_arg(&current_cmd, token_list->token);
        else
        {
            add_rdir(&current_cmd, token_list->next->token, token_list->type);
            token_list = token_list->next;
        }
        token_list = token_list->next;
    }
    return (*cmd_table);
}
