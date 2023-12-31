/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:55:33 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/15 14:29:54 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*find_extand_here(char *token, size_t start, size_t len,
		t_shell *shell)
{
	t_env	*cur_env;
	int		check;

	cur_env = shell->envp;
	check = 0;
	start++;
	len--;
	while (cur_env)
	{
		if (ft_strlen(cur_env->key) == len)
		{
			check = ft_strncmp(token + start, cur_env->key, len);
			if (check == FALSE)
				return (cur_env->value);
		}
		cur_env = cur_env->next;
	}
	return (NULL);
}

int	make_new_ext_here(t_expand *test, size_t start, size_t len, char *ext)
{
	char	*s1;
	char	*s2;
	char	*tmp;

	tmp = NULL;
	s1 = NULL;
	s2 = NULL;
	s1 = ft_substr(test->token, 0, start);
	s2 = ft_substr(test->token, start + len, ft_strlen(test->token + start
				+ len));
	if (!check_str(s1, s2, NULL, 2))
		return (free(s1), free(s2), ERROR);
	tmp = ft_strjoin(s1, ext);
	if (tmp == NULL)
		return (free(s1), free(s2), ERROR);
	test->token = ft_strjoin(tmp, s2);
	if (test->token == NULL)
		return (free(s1), free(s2), free(tmp), ERROR);
	return (free(s1), free(s2), free(tmp), TRUE);
}

size_t	expand_one_here(t_expand *test, size_t pos, t_shell *shell)
{
	char	*ext;
	size_t	i;

	ext = NULL;
	i = 1;
	while (ft_isexpand(test->token[pos + i]))
		i++;
	ext = list_malloc(1, sizeof(char *));
	if (ext == NULL)
		return (mem_err_make_true(shell), FALSE);
	ext = find_extand_here(test->token, pos, i, shell);
	if (make_new_ext_here(test, pos, i, ext) == ERROR)
	{
		shell->mem_err_flg = TRUE;
		return (FALSE);
	}
	if (!ft_strlen(test->token))
	{
		test->token = NULL;
		return (0);
	}
	return (ft_strlen(ext));
}

static size_t	parse_expand_here(t_expand *test, size_t pos, t_shell *shell)
{
	size_t	i;

	i = 0;
	if (ft_isquote(test->token[pos + 1]))
		rm_ext_here(test, pos, 1, shell);
	else if (ft_isexpand(test->token[pos + 1]))
		i += expand_one_here(test, pos, shell);
	else if (test->token[pos + 1] == '?')
		i += expand_return_here(test, pos, shell);
	else
		i++;
	return (i);
}

char	*get_expand(char *token, t_shell *shell)
{
	t_expand	*test;
	size_t		i;

	test = list_malloc(1, sizeof(t_expand *));
	if (test == NULL)
		return (mem_err_make_true(shell), NULL);
	test->token = ft_strdup(token);
	if (test->token == NULL)
		return (mem_err_make_true(shell), NULL);
	i = 0;
	while (test->token[i])
	{
		if (test->token[i] == '$')
			i += parse_expand_here(test, i, shell);
		else
			i++;
		if (test->token == NULL)
			return (test->token);
	}
	return (test->token);
}

// char	*get_expand(char *token, t_shell *shell)
// {
// 	size_t	i;

// 	i = 0;
// 	while (token[i])
// 	{
// 		if (token[i] == '$')
// 			i += parse_expand_here(token, i, shell);
// 		else
// 			i++;
// 		if (token == NULL)
// 			return (token);
// 	}
// 	return (token);
// }

// bool expand_tokens_here(t_token *head, t_shell *shell)
// {
// 	t_token *current;
// 	bool here_check;

// 	here_check = FALSE;
// 	current = head;
// 	while(current)
// 	{
// 		if (here_check == TRUE)
// 			here_check = FALSE;
// 		else if (current->type == STR)
// 		{
// 			get_expand(current->token, shell);
// 			if (shell->mem_err_flg)
// 				return (FALSE);
// 		}
// 		if (current->type == HEREDOC)
// 			here_check = TRUE;
// 		current = current->next;
// 	}
// 	return (TRUE);
// }
