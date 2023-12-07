/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:25:52 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/07 16:19:35 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	rm_quote_str(char *current, t_shell *shell)
{
	size_t	i;
	int		quote;

	quote = 0;
	i = 0;
	while (current[i])
	{
		if (ft_isquote(current[i]))
		{
			quote = current[i];
			i += rm_ext_here(current, i + 1, 1, shell);
		}
		if (shell->mem_err_flg == TRUE)
			return (FALSE);
		if (quote)
		{
			while (current[i] && current[i] != quote)
				i++;
			rm_ext_here(current, i, 1, shell);
			quote = FALSE;
		}
		else
			i++;
		if (shell->mem_err_flg == TRUE)
			return (FALSE);
	}
	return (TRUE);
}

// bool rm_quotes(t_token *head, t_shell *shell)
// {
// 	t_token *current;
// 	bool	prev_here;

// 	prev_here = FALSE;
// 	current = head;
// 	while (current)
// 	{
// 		if (prev_here == FALSE && current->type == STR)
// 			rm_quote_str(current->token, shell);
// 		if (shell->mem_err_flg == TRUE)
// 			return (FALSE);
// 		if (current->type == HEREDOC)
// 			prev_here = TRUE;
// 		if (prev_here == TRUE && current->type != HEREDOC)
// 			prev_here = FALSE;
// 		current = current->next;
// 	}
// 	return (TRUE);
// }
