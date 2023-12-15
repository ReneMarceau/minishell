/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:05:05 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/15 00:18:58 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	make_tk_null(t_token *current)
{
	current->type = TK_NULL;
	current->token = NULL;
	return (FALSE);
}

int	rm_ext(t_token *current, size_t start, size_t len, t_shell *shell)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	s1 = ft_substr(current->token, 0, start);
	s2 = ft_substr(current->token, start + len, ft_strlen(current->token + start
				+ len));
	if (!check_str(s1, s2, NULL, 2))
	{
		shell->mem_err_flg = TRUE;
		return (free(s1), free(s2), ERROR);
	}
	current->token = ft_strjoin(s1, s2);
	if (current->token == NULL)
	{
		shell->mem_err_flg = TRUE;
		return (free(s1), free(s2), ERROR);
	}
	return (free(s1), free(s2), TRUE);
}

char *rm_ext_here(t_expand *test, size_t start, size_t len, t_shell *shell)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	s1 = ft_substr(test->token, 0, start);
	s2 = ft_substr(test->token, start + len, ft_strlen(test->token + start + len));
	if (!check_str(s1, s2, NULL, 2))
	{
		shell->mem_err_flg = TRUE;
		return (free(s1), free(s2), NULL);
	}
	test->token = ft_strjoin(s1, s2);
	if (test->token == NULL)
	{
		shell->mem_err_flg = TRUE;
		return (free(s1), free(s2), NULL);
	}
	return (free(s1), free(s2), test->token);
}

char *rm_ext_here_quote(char *test, size_t start, size_t len, t_shell *shell)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	s1 = ft_substr(test, 0, start);
	s2 = ft_substr(test, start + len, ft_strlen(test + start + len));
	if (!check_str(s1, s2, NULL, 2))
	{
		shell->mem_err_flg = TRUE;
		return (free(s1), free(s2), NULL);
	}
	test = ft_strjoin(s1, s2);
	if (test == NULL)
	{
		shell->mem_err_flg = TRUE;
		return (free(s1), free(s2), NULL);
	}
	return (free(s1), free(s2), test);
}
