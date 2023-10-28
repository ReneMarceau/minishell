// #include "minishell.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
#include "../includes/global.h"


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
