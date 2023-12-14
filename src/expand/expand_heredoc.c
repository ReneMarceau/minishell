/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:55:33 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/14 15:43:00 by wmillett         ###   ########.fr       */
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

int	make_new_ext_here(char *token, size_t start, size_t len, char *ext)
{
	char	*s1;
	char	*s2;
	char	*tmp;

	tmp = NULL;
	s1 = NULL;
	s2 = NULL;
	s1 = ft_substr(token, 0, start);
	s2 = ft_substr(token, start + len, ft_strlen(token + start + len));
	if (!check_str(s1, s2, NULL, 2))
		return (free(s1), free(s2), ERROR);
	tmp = ft_strjoin(s1, ext);
	if (tmp == NULL)
		return (free(s1), free(s2), ERROR);
	free(token);
	token = ft_strjoin(tmp, s2);
	if (token == NULL)
		return (free(s1), free(s2), free(tmp), ERROR);
	add_garbage(token);
	return (free(s1), free(s2), free(tmp), TRUE);
}

size_t	expand_one_here(char *token, size_t pos, t_shell *shell)
{
	char	*ext;
	size_t	i;

	ext = NULL;
	i = 1;
	while (ft_isexpand(token[pos + i]))
		i++;
	ext = list_malloc(1, sizeof(char *));
	if (ext == NULL)
		return (mem_err_make_true(shell), FALSE);
	ext = find_extand_here(token, pos, i, shell);
	if (make_new_ext_here(token, pos, i, ext) == ERROR)
	{
		shell->mem_err_flg = TRUE;
		return (FALSE);
	}
	if (!ft_strlen(token))
	{
		token = NULL;
		return (0);
	}
	return (ft_strlen(ext));
}

static size_t	parse_expand_here(char *token, size_t pos, t_shell *shell)
{
	size_t	i;

	i = 0;
	if (ft_isquote(token[pos + 1]))
		rm_ext_here(token, pos, 1, shell);
	else if (ft_isexpand(token[pos + 1]))
		i += expand_one_here(token, pos, shell);
	else if (token[pos + 1] == '?')
		i += expand_return_here(token, pos, shell);
	else
		i++;
	return (i);
}

char	*get_expand(char *token, t_shell *shell)
{
	size_t	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '$')
			i += parse_expand_here(token, i, shell);
		else
			i++;
		if (token == NULL)
			return (token);
	}
	return (token);
}

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
