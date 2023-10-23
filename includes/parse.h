/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:24:09 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/22 18:36:05 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

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
//general definitions -------
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 1
# define FAILURE 0
# define INVALID -1
# define FINISH 1
# define DONE 0
# define NOT_FINISH 0
//definitions for parse ------
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

enum e_cmd
{
	CMD,
	PIPE,
	REDIR,
	TXT,
	QUOTE,
	D_QUOTE,
	
};


//parse -----------------------
//utils_mem -------------------
void	mem(void);
int 	gmallock(t_list **mem_list, void *to_alloc);
void 	clean_mem(t_list **mem_list);
#endif