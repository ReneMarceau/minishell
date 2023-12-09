/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:33:18 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/07 16:54:11 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	overwrite_quote(char *token, size_t pos)
{
	const char	q_type = token[pos];
	size_t		i;

	i = 1;
	token[pos] = SEP;
	if (token[pos + i] == q_type)
	{
		token[pos + i] = SEP;
		return (i + 1);
	}
	while (token[pos + i] && token[pos + i] != q_type)
		i++;
	if (token[pos + i] == q_type)
		token[pos + i] = SEP;
	return (i + 1);
}

void	through_rm_quote(char *token)
{
	int	check;
	int	i;

	i = 0;
	while (token[i])
	{
		check = 0;
		if (token[i] == '\"')
			i += overwrite_quote(token, i);
		else if (token[i] == '\'')
			i += overwrite_quote(token, i);
		else
			i++;
	}
}

char	*convert_to_char(char **to_group, t_shell *shell)
{
	char	*res;
	size_t	i;

	i = 0;
	res = NULL;
	if (to_group[i] && to_group[i + 1])
		res = ft_strjoin(to_group[i], to_group[i + 1]);
	else
		return (NULL);
	if (!res)
		return (mem_err_true(to_group, shell), NULL);
	i = 3;
	while (to_group[i])
	{
		res = ft_strjoin(res, to_group[i]);
		if (!res)
			return (mem_err_true(to_group, shell), NULL);
		i++;
	}
	return (res);
}

void	get_rid_quote(char *token, t_shell *shell)
{
	char	**res_split;

	through_rm_quote(token);
	res_split = ft_split(token, SEP);
	if (!res_split)
	{
		shell->mem_err_flg = TRUE;
		return ;
	}
	token = convert_to_char(res_split, shell);
}

bool	rm_quotes(t_token *head, t_shell *shell)
{
	t_token	*current;
	bool	prev_here;

	prev_here = FALSE;
	current = head;
	while (current)
	{
		if (prev_here == FALSE && current->type == STR)
			get_rid_quote(current->token, shell);
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
