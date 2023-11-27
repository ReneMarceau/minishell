/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:23:34 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/26 21:26:30 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"

// static void print_lst(t_token *head) 
// {
//     t_token *current = head;

//     while (current != NULL) 
// 	{
//         printf("value: %s --- ", (char *)current->token);
//         if (current->type == STR)
//             printf("type: STR\n");
//         else if (current->type == REDIR_IN)
//             printf("type: REDIR_IN\n");
//         else if (current->type == REDIR_OUT)
//             printf("type: REDIR_OUT\n");
//         else if (current->type == REDIR_APPEND)
//             printf("type: APPEND\n");
//         else if (current->type == HEREDOC)
//             printf("type: HEREDOC\n");
//         else if (current->type == PIPE)
//             printf("type: PIPE\n");
//         else if (current->type == TK_NULL)
//             printf("type: TK_NULL\n");
//         current = current->next;
//     }
//     printf("--------------------\n");
// }

// static void print_cmd_table(t_cmd *head)
// {
//     t_cmd *current_cmd;
//     t_rdir *current_rdir;
//     int i;

//     current_cmd = head;
//     while (current_cmd != NULL)
//     {
//         i = 0;
//         printf("index: %d\n", current_cmd->index);
//         while (current_cmd->args[i] != NULL)
//         {
//             printf("args[%d]: %s\n", i, current_cmd->args[i]);
//             i++;
//         }
//         current_rdir = current_cmd->rdir;
//         while (current_rdir != NULL)
//         {
//             printf("rdir file: %s\n", current_rdir->value);
//             printf("type: ");
//             if (current_rdir->type == REDIR_IN)
//                 printf("REDIR_IN\n");
//             else if (current_rdir->type == REDIR_OUT)
//                 printf("REDIR_OUT\n");
//             else if (current_rdir->type == REDIR_APPEND)
//                 printf("REDIR_APPEND\n");
//             else if (current_rdir->type == HEREDOC)
//                 printf("HEREDOC\n");
//             current_rdir = current_rdir->next;
//         }
//         printf("pid: %d\n", current_cmd->pid);
//         printf("--------------------\n");
//         current_cmd = current_cmd->next;
//     }
//     printf("\n");
// }

t_cmd *parsing(char *input, t_shell *shell)
{
    t_cmd   *cmd_table;
    t_token *token_list;
    
    token_list = NULL;
    if (!check_quotes(input) || !check_token(input))
        return (NULL);
    token_list = tokenize(input, token_list);
    if (token_list == NULL)
    {
        shell->mem_err_flg = TRUE;
        return ((t_cmd *)clean_all());
    }
    //print_lst(token_list);
    expand_tokens(token_list, shell);
    if (shell->mem_err_flg)
        return ((t_cmd *)clean_all());
    cmd_table = fill_cmd_table(token_list);
    if (cmd_table == NULL)
    {
        shell->mem_err_flg = TRUE;
        return ((t_cmd *)clean_all());
    }
    //print_cmd_table(cmd_table);
    return (cmd_table);
}

