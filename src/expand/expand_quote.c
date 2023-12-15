/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:25:52 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/15 11:09:27 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static size_t	get_rid_quotes_here(t_expand *test, size_t pos, t_shell *shell)
{
	char	quote;

	quote = test->token[pos];
	rm_ext_here(test, pos, 1, shell);
	if (shell->mem_err_flg == TRUE)
		return (pos);
	while (test->token[pos] && test->token[pos] != quote)
		pos++;
	rm_ext_here(test, pos, 1, shell);
	return (pos);
}

char	*rm_quote_str_here(char *delimiter, t_shell *shell)
{
	size_t		i;
	t_expand	*test;

	test = list_malloc(1, sizeof(t_expand *));
	if (test == NULL)
	{
		shell->mem_err_flg = TRUE;
		return (FALSE);
	}
	add_garbage(test);
	test->token = delimiter;
	i = 0;
	while (test->token[i])
	{
		if (ft_isquote(test->token[i]))
			i = get_rid_quotes_here(test, i, shell);
		else
			i++;
		if (shell->mem_err_flg == TRUE)
			return (NULL);
	}
	return (test->token);
}

static size_t	get_rid_quotes(char *current, size_t pos, t_shell *shell)
{
	char	quote;

	quote = current[pos];
	rm_ext_here_quote(current, pos, 1, shell);
	if (shell->mem_err_flg == TRUE)
		return (pos);
	while (current[pos] && current[pos] != quote)
		pos++;
	rm_ext_here_quote(current, pos, 1, shell);
	return (pos);
}

bool	rm_quote_str(char *current, t_shell *shell)
{
	size_t	i;

	i = 0;
	while (current[i])
	{
		if (ft_isquote(current[i]))
			i = get_rid_quotes(current, i, shell);
		else
			i++;
		if (shell->mem_err_flg == TRUE)
			return (FALSE);
	}
	return (TRUE);
}

bool	rm_quotes_exp(t_token *head, t_shell *shell)
{
	t_token	*current;
	bool	prev_here;

	prev_here = FALSE;
	current = head;
	while (current)
	{
		if (prev_here == FALSE && current->type == STR)
			rm_quote_str(current->token, shell);
		if (shell->mem_err_flg == TRUE)
			return (FALSE);
		if (current->type == HEREDOC)
			prev_here = TRUE;
		if (prev_here == TRUE && current->type != HEREDOC)
			prev_here = FALSE;
		current = current->next;
	}
	return (TRUE);
}
