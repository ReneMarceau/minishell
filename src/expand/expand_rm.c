/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:05:05 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/14 15:43:24 by wmillett         ###   ########.fr       */
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

int	rm_ext_here(char *current, size_t start, size_t len, t_shell *shell)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	s1 = ft_substr(current, 0, start);
	s2 = ft_substr(current, start + len, ft_strlen(current + start + len));
	if (!check_str(s1, s2, NULL, 2))
	{
		shell->mem_err_flg = TRUE;
		return (free(s1), free(s2), ERROR);
	}
	free(current);
	current = ft_strjoin(s1, s2);
	if (current == NULL)
	{
		shell->mem_err_flg = TRUE;
		return (free(s1), free(s2), ERROR);
	}
	return (free(s1), free(s2), TRUE);
}
