/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:05:05 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/29 17:09:24 by wmillett         ###   ########.fr       */
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
