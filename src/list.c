/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:54:25 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/10 22:14:33 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

// t_args	*new_args(char *token)
// {
// 	t_args	*s1;
// 	const size_t len = ft_strlen(token);
// 	s1 = (t_args *)malloc(sizeof(char) * len + sizeof(t_args) + 1);
// 	if (!s1)
// 		return (NULL);
// 	s1->token = token;
// 	s1->next = NULL;
// 	return (s1);
// }

// size_t args_size(t_args *lst)
// {
// 	size_t	size;

// 	size = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		size++;
// 	}
// 	return (size);
// }

// void	add_arg(t_args **lst, t_args *newnode)
// {
// 	t_args	*start;

// 	start = *lst;
// 	if (*lst)
// 	{
// 		while (start->next)
// 			start = start->next;
// 		start->next = newnode;
// 	}
// 	else
// 		*lst = newnode;
// }

void free_lst(t_args *head)
{
	t_args *current;
	t_args *tmp;
	
	current = head;
	while (current != NULL) 
	{
    	tmp = current;
    	current = current->next;
    	free(tmp);
    }
}

t_args *convert_to_lst(char **array, t_args *head, t_args *current, t_args *newnode) 
{
	size_t i;

	current = head;
	i = 0;
	while (array[i] != NULL)
	{
		newnode = (t_args *)malloc(sizeof(t_args));
        if (newnode == NULL) 
            return NULL;
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
