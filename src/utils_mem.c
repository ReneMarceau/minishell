/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:02:02 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/27 20:34:07 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

// static void remove_mem(void *to_free)
// {
// 	if(to_free)
// 	{
// 		// free(to_free);
// 		to_free = NULL;
// 		mem()->size--;
// 	}
// }

// t_list **list_mem(void)
// {
// 	static t_list *a;
	
// 	return(&a);
// }

// t_mem *mem(void)
// {
// 	static t_mem a;
	
// 	a.list = list_mem();
// 	return(&a);
// }

// int gmallock(void *to_alloc)
// {
// 	to_alloc = malloc(sizeof(void*));
// 	if (to_alloc == NULL)
// 		return(ERROR);
// 	ft_lstadd_back(mem()->list, to_alloc);
// 	mem()->size++;
// 	return(FINISH);
// }

// void clean_mem(void)
// {
// 	if (mem()->size)
// 		ft_lstclear(mem()->list, remove_mem);
// }

t_memlist *mem_data(void)
{
	static t_memlist head = {NULL, NULL};

	return &head;
}

void *list_malloc(size_t nmemb, size_t size)
{
	t_memlist *to_alloc;

	to_alloc = ft_calloc(1, sizeof(t_memlist));
	if (!to_alloc)
		return NULL;

	to_alloc->mem_next = mem_data()->mem_next;
	mem_data()->mem_next = to_alloc;

	to_alloc->address = ft_calloc(nmemb, size);
	if (!to_alloc->address)
		return NULL;
	return to_alloc->address;
}

void free_one(void *address)
{
	t_memlist *gc_ptr;
	t_memlist *ptr_tmp;

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
			return;
		}
		ptr_tmp = gc_ptr;
		gc_ptr = gc_ptr->mem_next;
	}
}

void all_free(void)
{
	t_memlist *gc_ptr;
	t_memlist *ptr_tmp;

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

// int addPointerToList(t_list** head, void* data) 
// {
//     // Create a new t_list
// 	t_list* current;
//     t_list* newt_list;
	
// 	newt_list = (t_list*)malloc(sizeof(t_list));
//     if (newt_list == NULL) 
// 		return (ERROR);

//     // Set the data for the new t_list
//     newt_list->content = data;
//     newt_list->next = NULL;

//     // If the list is empty, make the new t_list the head
//     if (*head == NULL) {
//         *head = newt_list;
//     } else {
//         // Otherwise, traverse the list and add the new t_list at the end
// 	current = *head;
//         while (current->next != NULL) 
//             current = current->next;
//         current->next = newt_list;
//     }
// }
