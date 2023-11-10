/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:44:28 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/09 22:14:56 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

size_t through_quote(char *input, size_t i, char *dst, size_t pos_dst)
{
	const char quote = input[i];
	size_t j;

	j = 1;
	if (dst)
		dst[pos_dst++] = input[i];
	i++;
	while(input[i] && input[i] != quote)
	{
		if (dst)
			dst[pos_dst++] = input[i];
		i++;
		j++;
	}
	if (dst)
		dst[pos_dst] = input[i];
	return (j + 1);
}

size_t through_special(char *input, size_t i)
{
	const char a = input[i];
	size_t j;

	j = 1;
	while(input[++i] == a)
		j++;
	return (j);
}

t_args *tokenize(char *input, t_args *table)
{
	char *converted_input;
	char **tokens;
	
	converted_input = str_sel_dup(input);
	tokens = ft_split(converted_input, SEP);
	convert_to_lst(tokens, table);
	return(table);
}
