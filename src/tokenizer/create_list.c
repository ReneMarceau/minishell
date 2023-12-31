/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:54:25 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/07 18:15:52 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"

t_token	*convert_to_lst(char **array, t_token *head, t_token *current,
		t_token *newnode)
{
	size_t	i;

	current = head;
	i = 0;
	while (array[i] != NULL)
	{
		newnode = (t_token *)list_malloc(sizeof(t_token), 1);
		if (newnode == NULL)
			return (NULL);
		newnode->token = array[i];
		newnode->type = analyze_token(newnode);
		newnode->next = NULL;
		if (head == NULL)
		{
			head = newnode;
			current = newnode;
		}
		else
		{
			current->next = newnode;
			current = newnode;
		}
		i++;
	}
	return (head);
}
