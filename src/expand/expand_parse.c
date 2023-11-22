/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:16 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/22 14:45:05 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static size_t parse_expand(t_token* current, size_t pos, bool in_quote, t_env *env)
{
	size_t i;

	i = 0;
	if (ft_isquote(current->token[pos + 1]) && in_quote == FALSE)
		rm_dollar(current, pos);
	else if (ft_isexpand(current->token[pos + 1]) && in_quote == TRUE)
		i += expand_one(current, pos, env) - 1;
	else if (ft_isexpand(current->token[pos + 1]))
		i += expand_one(current, pos, env);
	else if (current->token[pos + 1] == '?') 
		i++; //add fct to retrieve last return
	else
		i++;
	return (i);
}

static size_t check_in_quote(t_token *current, size_t pos, t_env *env)
{
	size_t i;

	i = 1;
	while(current->token[pos + i] != '\"' && current->token[pos + i])
	{
		if (current->token[pos + i] == '$')
			i += parse_expand(current, pos + i, TRUE, env);
		else
			i++;
	}
	if (current->token[pos + i] == '\"')
		i++;
	return (i);
}

static bool check_to_expand(t_token *current, t_env *env)
{
	size_t i;
	
	i = 0;
	while(current->token[i])
	{
		if (current->token[i] == '\'')
			i += through_single_quote(current->token, i);
		else if (current->token[i] == '\"')
		{
			i += check_in_quote(current, i, env);
			printf("i you want: %zu\n", i);
			printf("c you want: %c\n", current->token[i]);
		}
		else if (current->token[i] == '$')
			i += parse_expand(current, i, FALSE, env);
		else
			i++;
	}
	return (TRUE);
}

bool expand_tokens(t_token *head, t_env *env)
{
	t_token *current;
	bool check;
	bool here_check;

	here_check = FALSE;
	check = FALSE;
	current = head;
	while(current)
	{
		if (here_check == TRUE)
			here_check = FALSE;
		else if (current->type == STR)
		{
			check = check_to_expand(current, env);
			if (check == FALSE)
				return (FALSE);
		}
		if (current->type == HEREDOC)
			here_check = TRUE;
		current = current->next;
	}
	return (TRUE);
}
