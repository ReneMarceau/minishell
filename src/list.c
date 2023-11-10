/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:54:25 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/09 22:17:51 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

t_args	*new_args(char *token)
{
	t_args	*s1;
	const size_t len = ft_strlen(token);
	s1 = (t_args *)malloc(sizeof(char) * len + sizeof(t_args) + 1);
	if (!s1)
		return (NULL);
	s1->token = token;
	s1->next = NULL;
	return (s1);
}

size_t args_size(t_args *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	add_arg(t_args **lst, t_args *newnode)
{
	t_args	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}

t_args *convert_to_lst(char **tokens, t_args *table)
{
	const t_args **tmp = &table;
	size_t i;
	
	i = 0;
	while(tokens[i])
	{
		if (i == 0)
		{
			table = new_args(tokens[i]);
			table = table->next;
		}
		else
		{
			table = new_args(tokens[i]);
			add_arg(tmp, table);
			table = table->next;
			printf("tmp:%s\n", table->token);
		}
		// if (table == NULL)
		// 	return (NULL);
		i++;
	}
	return (table);
}
