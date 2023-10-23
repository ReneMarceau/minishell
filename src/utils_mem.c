/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:02:02 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/22 22:15:46 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

static void remove_mem(void *to_free)
{
	if(to_free)
	{
		// free(to_free);
		to_free = NULL;
	}
}

t_list *mem(void)
{
	static t_list a = {NULL, NULL};

	return(&a);
}

int gmallock(t_list **mem_list, void *to_alloc)
{
	to_alloc = malloc(sizeof(void*));
	if (to_alloc == NULL)
		return(ERROR);
	ft_lstadd_back(mem_list, to_alloc);
	// ft_lstclear();
	return(FINISH);
}

void clean_mem(t_list **mem_list)
{
	ft_lstclear(mem_list, remove_mem);
}
