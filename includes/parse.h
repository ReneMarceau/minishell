/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:24:09 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/09 22:15:26 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//libft -
# include "../libs/libft/inc/libft.h"
//debug  --------------------
// extern int DEBUG;
//librairies ----------------
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>

//readline
#include <readline/readline.h>
#include <readline/history.h>

//general definitions -------
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 1
# define FAILURE 0
# define INVALID -1
# define FINISH 1
//definitions for parse ------
# define SEP 19
# define OUT 0
# define IN_SINGLE 1
# define IN_DOUBLE 2
//definitions for print ------
# define CMD_MESSAGE "Command not found"
# define LEAVE_MESSAGE "exit"
# define NO_CMD -6
# define GO_EXIT -7
//error ----------------------
# define ATOL_ER -2147483650
# define NOINT_ER -2147483651
# define MEM_ER -2
# define MIN_ER -3
# define MAX_ER -4
# define INT_ER -5
# define TEST 100
# define THREAD_ERR "Failed to create a thread."
# define MUTEX_ERR "Failed to initialize mutex."
# define ARG_NB_ERR "Wrong number of arguments."
# define FORMAT_ERR "Invalid argument format."
# define MEM_ERR "Memory allocaton failed."
# define ATOL_ERR "Argument does not fit in an integer."
//structs --------------------

enum e_node
{
	CMD,
	STR,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC_IN,
	HEREDOC_OUT
};

typedef struct s_mem
{
	enum e_node	type;
	t_list **list;
	size_t	size;
}	t_mem;

typedef struct s_test
{
	int i;
	char c;
	size_t v;
	
} t_test;

typedef struct s_memlist
{
    void *address;
    struct s_memlist *mem_next;
}   t_memlist;

typedef struct s_cmd 
{
    int index;
    size_t nb_args;
    char **args;
    pid_t pid;
	enum e_node type;
    struct s_cmd *next;
}   t_cmd;

typedef struct s_args
{
	char *token;
	enum e_node type;
	struct s_args *next;
}	t_args;

//parse -----------------------
bool 		check_token(char *input);
bool 		check_quotes(char *input);
t_args 		*parse(char *input);
//utils_mem -------------------
t_memlist 	*mem_data(void);
void 		*list_malloc(size_t nmemb, size_t size);
void 		free_one(void *address);
void 		all_free(void);
//tokenize --------------------
t_args 		*tokenize(char *input, t_args *table);
//expand ----------------------
// int 		expand_tokens(char **tokens);
// int 		expand_one(char *arg, int pos);
//signal ----------------------
void 		signalhandler(void);
//utils_is -----------------------
bool 		ft_isquote(char a);
bool 		ft_isspecial(char a);
bool		is_sep(char c);
//meta_char -------------------
// int 		check_meta(char *input, int i);
//convert_input --------------------
// size_t 		count_arg(char *input, size_t i, size_t res);
size_t 		through_quote(char *input, size_t i, char *dst, size_t pos_dst);
size_t 		through_special(char *input, size_t i);
char		*str_sel_dup(char *s1);
//quote -----------------------
int 		in_single(char *input, int i);
int 		in_double(char *input, int i);
int 		in_quote(char *input, int i);
//list ------------------------
t_args 		*convert_to_lst(char **tokens, t_args *table);
t_args		*new_args(char *token);
size_t 		args_size(t_args *lst);
void		add_arg(t_args **lst, t_args *newnode);
#endif