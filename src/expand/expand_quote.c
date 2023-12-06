/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:25:52 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/05 20:34:15 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void remove_quote(t_token *current, t_shell *shell)
{
	size_t i;

	i = 0;
	while (current->token[i])
	{
		if (ft_isquote(current->token[i]))
			rm_ext(current, i, 1, shell);
		if (shell->mem_err_flg == TRUE)
			return ;
	}
}

bool rm_quotes(t_token *head, t_shell *shell)
{
	t_token *current;
	bool	prev_here;

	prev_here = FALSE;
	current = head;
	while (current)
	{
		if (prev_here == FALSE && current->type == STR && is_there_quote(current->token))
			remove_quote(current, shell);
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



// bool remove_quotes(t_token *head, t_shell *shell)
// {
// 	t_token *current;

// 	current = head;
// 	while (current)
// 	{
// 		i



		
// 	}

// }