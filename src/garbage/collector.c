/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:24:09 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/06 15:55:12 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_memlist	*mem_data(void)
{
	static t_memlist	head = {NULL, NULL};

	return (&head);
}

void	*list_malloc(size_t nmemb, size_t size)
{
	t_memlist	*to_alloc;

	to_alloc = ft_calloc(1, sizeof(t_memlist));
	if (!to_alloc)
		return (NULL);
	to_alloc->mem_next = mem_data()->mem_next;
	mem_data()->mem_next = to_alloc;
	to_alloc->address = ft_calloc(nmemb, size);
	if (!to_alloc->address)
		return (NULL);
	return (to_alloc->address);
}

void	free_one(void *address)
{
	t_memlist	*gc_ptr;
	t_memlist	*ptr_tmp;

	gc_ptr = mem_data()->mem_next;
	ptr_tmp = mem_data();
	while (gc_ptr)
	{
		if (gc_ptr->address == address)
		{
			ptr_tmp->mem_next = gc_ptr->mem_next;
			if (gc_ptr->address)
				free(gc_ptr->address);
			free(gc_ptr);
			return ;
		}
		ptr_tmp = gc_ptr;
		gc_ptr = gc_ptr->mem_next;
	}
}

void	all_free(void)
{
	t_memlist	*gc_ptr;
	t_memlist	*ptr_tmp;

	gc_ptr = mem_data()->mem_next;
	while (gc_ptr)
	{
		if (gc_ptr->address)
			free(gc_ptr->address);
		ptr_tmp = gc_ptr;
		gc_ptr = gc_ptr->mem_next;
		free(ptr_tmp);
	}
	mem_data()->mem_next = NULL;
}

void	add_garbage(void *to_add)
{
	// t_memlist	*ptr_tmp;

	// ptr_tmp = ft_calloc(1, sizeof(t_memlist));
	// if (!ptr_tmp)
	// 	return (FALSE);
	// ptr_tmp->mem_next = mem_data()->mem_next;
	// mem_data()->mem_next = ptr_tmp;
	// ptr_tmp->address = to_add;
	// return (TRUE);
	
	t_memlist	*ptr_tmp;

	ptr_tmp = mem_data()->mem_next;
	while (ptr_tmp->mem_next)
		ptr_tmp = ptr_tmp->mem_next;
	ptr_tmp->address = to_add;
	ptr_tmp->mem_next = NULL;
}
