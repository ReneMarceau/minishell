/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:30:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/10 21:02:05 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

size_t	count_tokens(t_cmd *table)
{
	size_t	i;

	i = 0;
	while (table->args[i])
		i++;
	return (i);
}

enum e_node	analyze_token(t_args *current)
{
	size_t	i;

	i = 0;
	while (current->token[i])
	{
		if (ft_isquote(current->token[i]) || ft_isalnum(current->token[i]))
			return (STR);
		if (current->token[i] == '<')
		{
			if (current->token[i + 1] == '<')
				return (HEREDOC_IN);
			return (REDIR_IN);
		}
		if (current->token[i] == '>')
		{
			if (current->token[i + 1] == '>')
				return (HEREDOC_OUT);
			return (REDIR_OUT);
		}
		if (current->token[i] == '|')
			return (PIPE);
		i++;
	}
	return (STR);
}

void	assign_token(t_args *head)
{
	t_args	*current;

	current = head;
	while (current->token)
	{
		current->type = analyze_token(current);
		current = current->next;
	}
}
