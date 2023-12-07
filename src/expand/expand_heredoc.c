/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:55:33 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/07 15:42:42 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char *find_extand_here(char *token, size_t start, size_t len, t_shell *shell)
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

int make_new_ext_here(char *token, size_t start, size_t len, char *ext)
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
	free(token);
	token = ft_strjoin(tmp, s2);
	if (token == NULL)
		return (ERROR);
	printf("make_new: %s\n", token);
	return (TRUE);
}

size_t expand_one_here(char *token, size_t pos, t_shell *shell)
{
	char *ext;
	size_t i;
	
	ext = NULL;
	i = 1;
	while(ft_isexpand(token[pos + i]))
		i++;
	ext = find_extand_here(token, pos, i, shell);
	// if (ext == NULL && pos == 0 && ft_strlen(token) == i)
	// 	return(0);
	if (make_new_ext_here(token, pos, i, ext) == ERROR)
	{
		shell->mem_err_flg = TRUE;
		return (FALSE);
	}
	printf("make_new: %s\n", token);
	if (!ft_strlen(token))
		return (0);
	return (ft_strlen(ext));
}

static size_t parse_expand_here(char	*token, size_t pos, t_shell *shell)
{
	size_t i;

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

char *get_expand(char *token, t_shell *shell)
{
	size_t i;
	
	i = 0;
	while(token[i])
	{
		printf("get_expand_loop\n");
		if (token[i] == '$')
			i += parse_expand_here(token, i, shell);
		else
			i++;
	}
	return (token);
}

bool expand_tokens_here(t_token *head, t_shell *shell)
{
	t_token *current;
	bool here_check;

	here_check = FALSE;
	current = head;
	while(current)
	{
		if (here_check == TRUE)
			here_check = FALSE;
		else if (current->type == STR)
		{
			get_expand(current->token, shell);
			if (shell->mem_err_flg)
				return (FALSE);
		}
		if (current->type == HEREDOC)
			here_check = TRUE;
		current = current->next;
	}
	return (TRUE);
}

















///////////////////




















// bool check_str(void *a, void *b, void *c, int type)
// {
// 	if (type == 3)
// 		if (c == NULL)
// 			return (FALSE);
// 	if (type >= 2)
// 		if (b == NULL)
// 			return (FALSE);
// 	if (type >= 1)
// 		if (a == NULL)
// 			return (FALSE);
// 	return (TRUE);
// }

// static char *find_extand(t_token *current, size_t start, size_t len, t_shell *shell)
// {
// 	t_env *cur_env;
// 	int check;

// 	cur_env = shell->envp;
// 	check = 0;
// 	start++;
// 	len--;
// 	while (cur_env)
// 	{
// 		if (ft_strlen(cur_env->key) == len)
// 		{
// 			check = ft_strncmp(current->token + start, cur_env->key, len);
// 			if (check == FALSE)
// 				return (cur_env->value);
// 		}
// 		cur_env = cur_env->next;
// 	}
// 	return (NULL);
// }

// int make_new_ext_tk(t_token *current, size_t start, size_t len, char *ext)
// {
// 	char *s1;
// 	char *s2;
// 	char *tmp;

// 	tmp = NULL;
// 	s1 = NULL;
// 	s2 = NULL;
// 	s1 = ft_substr(current->token, 0, start);
// 	s2 = ft_substr(current->token, start + len, ft_strlen(current->token + start + len));
// 	if (!check_str(s1, s2, NULL, 2))
// 		return (ERROR);
// 	tmp = ft_strjoin(s1, ext);
// 	if (tmp == NULL)
// 		return (ERROR); //should check in case of TK_NULL before doing all of this
// 	current->token = ft_strjoin(tmp, s2);
// 	if (current->token == NULL)
// 		return (ERROR); //should check in case of TK_NULL before doing all of this
// 	return (TRUE);
// }

// size_t expand_one(t_token* current, size_t pos, t_shell *shell)
// {
// 	char *ext;
// 	size_t i;
	
// 	ext = NULL;
// 	i = 1;
// 	while(ft_isexpand(current->token[pos + i]))
// 		i++;
// 	ext = find_extand(current, pos, i, shell);
// 	if (ext == NULL && pos == 0 && ft_strlen(current->token) == i)
// 	{
// 		current->type = TK_NULL;
// 		return(0);
// 	}
// 	else if (make_new_ext_tk(current, pos, i, ext) == ERROR)
// 	{
// 		shell->mem_err_flg = TRUE;
// 		return (FALSE);
// 	}
// 	if (!ft_strlen(current->token))
// 		return (make_tk_null(current));
// 	return (ft_strlen(ext));
// }










// //expand
// //////////////////////////////
// //parse

// static size_t parse_expand(t_token* current, size_t pos, bool in_quote, t_shell *shell)
// {
// 	size_t i;

// 	i = 0;
// 	if (ft_isquote(current->token[pos + 1]) && !in_quote)
// 		rm_ext(current, pos, 1, shell);
// 	else if (ft_isexpand(current->token[pos + 1]) && in_quote)
// 		i += expand_one(current, pos, shell) - 1;
// 	else if (ft_isexpand(current->token[pos + 1]))
// 		i += expand_one(current, pos, shell);
// 	else if (current->token[pos + 1] == '?' && in_quote)
// 		i += expand_return(current, pos, shell) - 1;
// 	else if (current->token[pos + 1] == '?')
// 		i += expand_return(current, pos, shell);
// 	else
// 		i++;
// 	return (i);
// }

// static size_t check_in_quote(t_token *current, size_t pos, t_shell *shell)
// {
// 	size_t i;

// 	i = 1;
// 	while(current->token[pos + i] != '\"' && current->token[pos + i])
// 	{
// 		if (current->token[pos + i] == '$')
// 			i += parse_expand(current, pos + i, TRUE, shell);
// 		else
// 			i++;
// 	}
// 	if (current->token[pos + i] == '\"')
// 		i++;
// 	return (i);
// }

// static bool check_to_expand(t_token *current, t_shell *shell)
// {
// 	size_t i;
	
// 	i = 0;
// 	while(current->token[i])
// 	{
// 		if (current->token[i] == '\'')
// 			i += through_single_quote(current->token, i);
// 		else if (current->token[i] == '\"')
// 		{
// 			i += check_in_quote(current, i, shell);
// 		}
// 		else if (current->token[i] == '$')
// 			i += parse_expand(current, i, FALSE, shell);
// 		else
// 			i++;
// 		if (current->type == TK_NULL)
// 			return (TRUE);
// 	}
// 	return (TRUE);
// }

// bool expand_tokens(t_token *head, t_shell *shell)
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
// 			check_to_expand(current, shell);
// 			if (shell->mem_err_flg)
// 				return (FALSE);
// 		}
// 		if (current->type == HEREDOC)
// 			here_check = TRUE;
// 		current = current->next;
// 	}
// 	return (TRUE);
// }
