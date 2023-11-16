/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:30:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/14 21:23:16 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"

enum e_node	analyze_token(t_token *current)
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
				return (HEREDOC);
			return (REDIR_IN);
		}
		if (current->token[i] == '>')
		{
			if (current->token[i + 1] == '>')
				return (REDIR_APPEND);
			return (REDIR_OUT);
		}
		if (current->token[i] == '|')
			return (PIPE);
		i++;
	}
	return (STR);
}
