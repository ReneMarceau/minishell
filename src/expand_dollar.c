/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:47:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/13 18:37:59 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void rm_dollar(t_args* current, size_t pos)
{
	char **tmp;
	
	tmp = NULL;
	current->toke[pos] = SEP;
	tmp = ft_split(current->token, SEP);
	current = ft_strjoin(tmp[0], tmp[1]);
}


// static char *get_extanded()
// {



	
// }


static bool check_str(char *s1, char *s2, char *ext)
{
	if (s1 == NULL || s2 == NULL || ext == NULL)
		return (FALSE);
	return (TRUE);
}

size_t expand_one(t_args* current, size_t pos)
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
	s1 = ft_substr(current->token, 0, pos);
	s2 = ft_substr(current->token, pos + i, ft_strlen(current->token + pos + i))
	// ext = get_extanded();
	// if (!check_str(s1, s2, s3))
	
	
	
	return (i);
}
