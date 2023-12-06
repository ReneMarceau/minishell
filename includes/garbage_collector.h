/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:24:09 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/06 15:55:31 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "global.h"
// # include <cstddef>

/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */
typedef struct s_memlist
{
	void				*address;
	struct s_memlist	*mem_next;
}						t_memlist;

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
t_memlist				*mem_data(void);
void					*list_malloc(size_t nmemb, size_t size);
void					free_one(void *address);
void					all_free(void);
void 					add_garbage(void *to_add);

void 					free_double_char(char **lst);
char 					*clean_all(void);
#endif