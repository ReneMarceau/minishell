/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:16 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/14 22:41:15 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static size_t parse_expand(t_args* current, size_t pos, bool in_quote, t_shell *shell)
{
	size_t i;

	i = 0;
	if (ft_isquote(current->token[pos + 1]) && in_quote == FALSE)
		rm_dollar(current, pos);
	else if (ft_isexpand(current->token[pos + 1]))
		i += expand_one(current, pos, shell);
	else if (current->token[pos + 1] == '?') 
		i++; //add fct to retrieve last return
	else
		i++;
	return (i);
}

static size_t check_in_quote(t_args *current, size_t pos, t_shell *shell)
{
	size_t i;

	i = 1;
	while(current->token[pos + i] != '\"')
	{
		if (current->token[pos + i] == '$')
			i += parse_expand(current, pos + i, TRUE, shell);
		i++;	
	}
	return (i);
}

static bool check_to_expand(t_args *current, t_shell *shell)
{
	size_t i;
	
	i = 0;
	while(current->token[i])
	{
		if (current->token[i] == '\'')
			i += through_quote(current->token, i, NULL, FALSE);
		else if (current->token[i] == '\"')
			i += check_in_quote(current, i, shell);
		else if (current->token[i] == '$')
			i += parse_expand(current, i, FALSE, shell);
		else
			i++;
	}
	return (TRUE);
}

bool expand_tokens(t_args *head, t_shell *shell)
{
	t_args *current;
	bool check;

	check = FALSE;
	current = head;
	while(current)
	{
		if (current->type == STR)
		{
			check = check_to_expand(current, shell);
			if (check == FALSE)
				return (FALSE);
		}
		current = current->next;
	}
	return (TRUE);
}
