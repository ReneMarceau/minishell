/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:05:05 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/04 16:56:45 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// int rm_dollar(t_token *current, size_t start)
// {
// 	char *s1;
// 	char *s2;
// 	char *tmp;

// 	tmp = NULL;
// 	s1 = NULL;
// 	s2 = NULL;
// 	s1 = ft_substr(current->token, 0, start);
// 	s2 = ft_substr(current->token, start + 1, ft_strlen(current->token + start + 1));
// 	if (!check_str(s1, s2, NULL, 2))
// 		return (ERROR);
// 	current->token = ft_strjoin(s1, s2);
// 	if (current->token == NULL)
// 		return (ERROR);
// 	return (TRUE);
// }

size_t make_tk_null(t_token *current)
{
	current->type = TK_NULL;
	current->token = NULL;
	return (FALSE);
}

int rm_ext(t_token *current, size_t start, size_t len, t_shell *shell)
{
	char *s1;
	char *s2;
	char *tmp;

	tmp = NULL;
	s1 = NULL;
	s2 = NULL;
	s1 = ft_substr(current->token, 0, start);
	s2 = ft_substr(current->token, start + len, ft_strlen(current->token + start + len));
	if (!check_str(s1, s2, NULL, 2))
	{
		shell->mem_err_flg = TRUE;
		return (ERROR);
	}
	current->token = ft_strjoin(s1, s2);
	if (current->token == NULL)
	{
		shell->mem_err_flg = TRUE;
		return (ERROR);
	}
	return(TRUE);	
}

int rm_str_exp(char *token, size_t start, size_t len, t_shell *shell)
{
	char *s1;
	char *s2;
	char *tmp;

	tmp = NULL;
	s1 = NULL;
	s2 = NULL;
	s1 = ft_substr(token, 0, start);
	s2 = ft_substr(token, start + len, ft_strlen(token + start + len));
	if (!check_str(s1, s2, NULL, 2))
	{
		shell->mem_err_flg = TRUE;
		return (ERROR);
	}
	token = ft_strjoin(s1, s2);
	if (token == NULL)
	{
		shell->mem_err_flg = TRUE;
		return (ERROR);
	}
	return(TRUE);
}

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
	while (current->token)
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
