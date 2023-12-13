/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:24:09 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/12 21:23:42 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
# include "global.h"

/* *************** ***************           *************** *************** */
/*                                  Macros                                   */
/* *************** ***************           *************** *************** */

//definitions for parse ------
# define SEP 19
# define OUT 0
# define IN_SINGLE 1
# define IN_DOUBLE 2
# define ERROR -1

//For signals
# define RESET_SIG 1
# define IN_INTERFACE 2
# define IN_HEREDOC 3
# define IN_PROCESS 4

/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */
enum				e_node
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
	char			*token;
	enum e_node		type;
	struct s_token	*next;
}					t_token;

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */

//parse -----------------------
void 				mem_err_make_true(t_shell *shell);
void 				mem_err_true(char **tofree, t_shell *shell);
bool				check_token(char *input);
bool				check_quotes(char *input);

//tokenize --------------------
size_t				through_single_quote(char *input, size_t i);
t_token				*tokenize(char *input, t_token *table);

//expand_parse ----------------------
bool				expand_tokens(t_token *head, t_shell *shell);

//expand_dollar ----------------------
bool				check_str(void *a, void *b, void *c, int type);
int					make_new_ext_tk(t_token *current, size_t start, size_t len,
						char *ext);
size_t				expand_one(t_token *current, size_t pos, t_shell *shell);

//expand_return --------------------
size_t				expand_return(t_token *current, size_t start,
						t_shell *shell);
size_t 				expand_return_here(char *current, size_t start, t_shell *shell);

//expand_rm ------------------------
// int					rm_dollar(t_token *current, size_t start);
int 				rm_ext(t_token *current, size_t start, size_t len, t_shell *shell);
size_t 				make_tk_null(t_token *current);
int 				rm_ext_here(char *current, size_t start, size_t len, t_shell *shell);

//expand_here ---------------------
int 				make_new_ext_here(char *token, size_t start, size_t len, char *ext);

//expand_quote --------------------
bool 				rm_quote_str(char *current, t_shell *shell);
bool 				rm_quotes_exp(t_token *head, t_shell *shell);
//utils_is -----------------------
bool				ft_isquote(char c);
bool				ft_isspecial(char c);
bool				is_sep(char c);
bool				ft_isexpand(char c);
bool 				is_there_quote(char *token);

//convert_input --------------------
size_t				through_quote(char *input, size_t i, char *dst,
						size_t pos_dst);
size_t				through_special(char *input, size_t i);
char				*str_sel_dup(char *s1);

//list ------------------------
t_token				*convert_to_lst(char **array, t_token *head,
						t_token *current, t_token *newnode);

//assign_token -----------------
enum e_node			analyze_token(t_token *current);

//fill_cmd_table ----------------
t_cmd				*fill_cmd_table(t_token *token_list);
t_rdir				*create_redir(char *file, int type);
bool    			is_valid_token(t_token *token);
void				add_rdir(t_cmd **head, char *file, int type);
void				add_arg(t_cmd **head, char *arg);

//signal_parse -----------------
int *state_sigint(int context);
// void sig_handle(t_shell *shell, int type);

//signal -----------------------
void treat_sig(int signal, siginfo_t *info, void *context);
void treat_here(int signal, siginfo_t *info, void *context);
void treat_in_process(int signal, siginfo_t *info, void *context);

//signal_set -------------------
void modify_sig_setup(void);
void sig_init(t_shell *shell);
void set_to_heredoc(t_shell *shell);
void set_to_process(t_shell *shell);



bool expand_tokens_here(t_token *head, t_shell *shell);//test_to_rm
#endif