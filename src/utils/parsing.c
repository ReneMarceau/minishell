/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:42:57 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/13 12:02:19 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"

void    display_cmd_table(t_cmd *cmd_table)
{
    t_cmd   *tmp;
    t_rdir  *tmp_rdir;
    int     i;

    tmp = cmd_table;
    i = 0;
    while (tmp)
    {
        printf("index : %d\n", tmp->index);
        while (tmp->args[i])
        {
            printf("arg[%d]: %s\n", i, tmp->args[i]);
            i++;
        }
        tmp_rdir = tmp->rdir;
        while (tmp_rdir)
        {
            printf("redir file: %s\n", tmp_rdir->value);
            printf("redir type: %d\n", tmp_rdir->type);
            tmp_rdir = tmp_rdir->next;
        }
        printf("pid: %d\n", tmp->pid);
        printf("\n");
        i = 0;
        tmp = tmp->next;
    }
}

t_rdir  *create_redir(char *file, int type)
{
    t_rdir  *new_rdir;
    
    new_rdir = (t_rdir *)ft_calloc(1, sizeof(t_rdir));
    if (new_rdir == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    new_rdir->value = ft_strdup(file);
    new_rdir->type = type;
    new_rdir->next = NULL;
    return (new_rdir);
}

void    add_redir(t_rdir **head, t_rdir *new_rdir)
{
    t_rdir  *tmp;

    if (new_rdir == NULL)
        return ;
    tmp = *head;
    if (*head)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_rdir;
    }
    else
        *head = new_rdir;
}

t_cmd   *create_cmd(char *cmd, int index, t_rdir *rdir)
{
    t_cmd *new_cmd;

    new_cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
    if (new_cmd == NULL)
        return (print_error(ERR_MALLOC, NULL), NULL);
    new_cmd->index = index;
    new_cmd->args = ft_split(cmd, ' ');
    new_cmd->rdir = rdir;
    new_cmd->pid = 69;
    new_cmd->next = NULL;
    return (new_cmd);
}

void    add_cmd(t_cmd **head, t_cmd *new_cmd)
{
    t_cmd *tmp;

    if (new_cmd == NULL)
        return ;
    tmp = *head;
    if (*head)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_cmd;
    }
    else
        *head = new_cmd;
}

t_cmd    *parsing_test(void)
{
    t_cmd	*cmd_table;

    cmd_table = NULL;
    add_cmd(&cmd_table, create_cmd("ls", 0, NULL));
    add_cmd(&cmd_table, create_cmd("cat -e", 1, create_redir("Makefile", INPUT)));
    display_cmd_table(cmd_table);
    return (cmd_table);
}
