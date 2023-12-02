/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:55:33 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/29 17:06:44 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char *get_ext(char *token, size_t start, size_t len, t_shell *shell)
{
	t_env *cur_env;
	int check;

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

int make_new_str(char *token, size_t start, size_t len, char *ext)
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
		return (ERROR);
	tmp = ft_strjoin(s1, ext);
	if (tmp == NULL)
		return (ERROR);
	token = ft_strjoin(tmp, s2);
	if (token == NULL)
		return (ERROR);
	return (TRUE);
}

size_t expand_single(char *token, size_t pos, t_shell *shell)
{
	char *ext;
	size_t i;
	
	ext = NULL;
	i = 1;
	while(ft_isexpand(token[pos + i]))
		i++;
	ext = get_ext(token, pos, i, shell);
	if (ext == NULL && pos == 0 && ft_strlen(token) == i)
	{
		// current->type = TK_NULL;
		return(0);
	}
	else if (make_new_str(token, pos, i, ext) == ERROR)
	{
		shell->mem_err_flg = TRUE;
		return (FALSE);
	}
	// if (!ft_strlen(token))
	// 	return (make_tk_null(token));
	return (ft_strlen(ext));
}





/////////////////////////

static size_t parse_expand(char	*token, size_t pos, t_shell *shell)
{
	size_t i;

	i = 0;
	if (ft_isquote(token[pos + 1]))
		rm_str_exp(token, pos, 1, shell);
	else if (ft_isexpand(token[pos + 1]))
		i += expand_single(token, pos, shell);
	else if (token[pos + 1] == '?')
		i += return_exp(token, pos, shell);
	else
		i++;
	return (i);
}

char *get_expand(char *token, t_shell *shell)
{
	size_t i;
	
	i = 0;
	while(token[i])
	{
		if (token[i] == '$')
			i += parse_expand(token, i, shell);
		else
			i++;
	}
	return (token);
}
