/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:25:30 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/15 11:10:11 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "error.h"
#include "global.h"

int	count_node_env(t_env *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_env	*find_env(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == true)
			return (env);
		env = env->next;
	}
	return (NULL);
}

t_env	*create_node_env(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (new_node == NULL)
		return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
	new_node->key = ft_strdup(key);
	if (new_node->key == NULL)
		return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
	new_node->value = ft_strdup(value);
	if (new_node->value == NULL)
		return (print_error(ERR_MALLOC, NULL, EXIT_FAILURE), NULL);
	new_node->next = NULL;
	return (new_node);
}

void	insert_env(t_env **head, t_env *new_node)
{
	t_env	*tmp;

	if (new_node == NULL)
		return ;
	tmp = *head;
	if (*head)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		*head = new_node;
}

void	unset_env(t_env **head, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = *head;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == true)
		{
			if (prev != NULL)
				prev->next = tmp->next;
			else
				*head = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
