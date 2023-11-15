/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:47:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/14 22:58:33 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void rm_dollar(t_args* current, size_t pos)
{
	char **tmp;
	
	tmp = NULL;
	current->token[pos] = SEP;
	// tmp = ft_split(current->token, SEP);
	// current = ft_strjoin(tmp[0], tmp[1]);
}

static int find_extand(t_args *current, int start, int end, t_shell *shell)
{
	int i;
	int check;

	check = 0;
	i = 0;
	while (shell->env[i])
	{
		check = ft_strncmp(++current, shell->env[i], (end - 1) - (start + 1));
		if (check == FALSE)
			return (i);
		i++;
	}
	return (ERROR);
}



static char *get_extanded(t_args *current, int start, int end, t_shell *shell)
{	
	const int pos_ext = find_extand(current, start, end, shell);

	if (pos_ext == ERROR)


	
}

static bool check_str(char *s1, char *s2, char *ext)
{
	if (s1 == NULL || s2 == NULL || ext == NULL)
		return (FALSE);
	return (TRUE);
}

size_t expand_one(t_args* current, size_t pos, t_shell *shell)
{
	char *s1;
	char *s2;
	char *ext;
	size_t i;

	ext = NULL;
	s1 = NULL;
	s2 = NULL;
	i = 1;
	while(ft_isexpand(current->token[pos + i]))
		i++;
	ext = get_extanded(current, pos, pos + i, shell);
	// s1 = ft_substr(current->token, 0, pos);
	// s2 = ft_substr(current->token, pos + i, ft_strlen(current->token + pos + i));
	
	// if (!check_str(s1, s2, s3))

	return (i);
}
