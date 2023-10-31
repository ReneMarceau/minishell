/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:24:09 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/30 22:49:02 by wmillett         ###   ########.fr       */
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
	PIPE,
	REDIR,
	TXT,
	QUOTE,
	D_QUOTE,
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
    struct s_cmd *next;
}   t_cmd;

//parse -----------------------
int 	parse(char *input);
//utils_mem -------------------
t_memlist 	*mem_data(void);
void 		*list_malloc(size_t nmemb, size_t size);
void 		free_one(void *address);
void 		all_free(void);
//tokenize --------------------
char 		**tokenize(char *input);
//expand ----------------------
int 		expand_tokens(char **tokens);
//signal ----------------------
void 		signalhandler(void);
#endif