/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:24:09 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/15 00:53:37 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */


/* *************** ***************           *************** *************** */
/*                                  Macros                                   */
/* *************** ***************           *************** *************** */
//definitions for parse ------
# define SEP ' '
# define OUT 0
# define IN_SINGLE 1
# define IN_DOUBLE 2

/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */
enum e_node
{
    STR,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HEREDOC,
    TK_NULL
};

typedef struct s_token
{
    char *token;
    enum e_node type;
    struct s_token *next;
}   t_token;

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
//parse -----------------------
bool 	check_token(char *input);
bool 	check_quotes(char *input);
//tokenize --------------------
t_token *tokenize(char *input, t_token *table);
//expand_parse ----------------------

//expand_dollar ----------------------

//utils_is -----------------------
bool	ft_isquote(char c);
bool	ft_isspecial(char c);
bool	is_sep(char c);
bool	ft_isexpand(char c);
//convert_input --------------------
size_t  through_quote(char *input, size_t i, char *dst, size_t pos_dst);
size_t  through_special(char *input, size_t i);
char	*str_sel_dup(char *s1);
//quote -----------------------

//list ------------------------
t_token *convert_to_lst(char **array, t_token *head, t_token *current, t_token *newnode);
//assign_token -----------------
enum    e_node analyze_token(t_token *current);
//fill_cmd_table ----------------
t_cmd   *fill_cmd_table(t_token *token_list);
t_rdir  *create_redir(char *file, int type);
void    add_rdir(t_cmd **head, char *file, int type);
void    add_arg(t_cmd **head, char *arg);

#endif