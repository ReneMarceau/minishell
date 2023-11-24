/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:47:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/23 20:12:15 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// void rm_dollar(t_token* current, size_t pos) //doesn't work apparently
// {
// 	char **tmp;
	
// 	tmp = NULL;
// 	current->token[pos] = SEP;
// 	// tmp = ft_split(current->token, SEP);
// 	// current = ft_strjoin(tmp[0], tmp[1]);
// }

static char *find_extand(t_token *current, size_t start, size_t len, t_shell *shell)
{
	int check;
	t_env *cur_env;

	cur_env = shell->envp;
	check = 0;
	start++;
	len--;
	// printf("len: %zu\n", len);
	while (cur_env)
	{
		if (ft_strlen(cur_env->key) == len)
		{
			check = ft_strncmp(current->token + start, cur_env->key, len);
			if (check == FALSE)
				return (cur_env->value);
		}
		cur_env = cur_env->next;
	}
	return (NULL);
}

size_t make_tk_null(t_token *current)
{
	current->type = TK_NULL;
	current->token = NULL;
	return (FALSE);
}

static bool check_str(void *a, void *b, void *c, int type)
{
	if (type == 3)
		if (c == NULL)
			return (FALSE);
	if (type >= 2)
		if (b == NULL)
			return (FALSE);
	if (type >= 1)
		if (a == NULL)
			return (FALSE);
	return (TRUE);
}

int make_new_ext_tk(t_token *current, size_t start, size_t len, char *ext)
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
		return (ERROR);
	tmp = ft_strjoin(s1, ext);
	// if (tmp == NULL)
	// 	return (ERROR); //should check in case of TK_NULL before doing all of this
	// printf("s1: %s\n", s1);//test
	current->token = ft_strjoin(tmp, s2);
	// printf("cur_tok: %s\n", current->token);//test
	// if (current->token == NULL)
	// 	return (ERROR); //should check in case of TK_NULL before doing all of this
	return (TRUE);
}

int rm_ext(t_token *current, size_t start, size_t len)
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
		return (ERROR);
	current->token = ft_strjoin(s1, s2);
	if (current->token == NULL)
		return(ERROR);//error flag
	return(TRUE);	
}

size_t expand_one(t_token* current, size_t pos, t_shell *shell)
{
	char *ext;
	size_t i;
	
	ext = NULL;
	i = 1;
	while(ft_isexpand(current->token[pos + i]))
		i++;
	ext = find_extand(current, pos, i, shell);
	if (ext == NULL && pos == 0 && ft_strlen(current->token) == i)
	{
		current->type = TK_NULL;
		return(0);
	}
	else if (make_new_ext_tk(current, pos, i, ext) == ERROR)
		return (FALSE); //should deal with memory allocation failure here
	if (!ft_strlen(current->token))
		return (make_tk_null(current));
	return (ft_strlen(ext));
}
