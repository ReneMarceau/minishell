/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:44:28 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/24 16:56:50 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"

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

size_t through_single_quote(char *input, size_t i)
{
	size_t j;

	j = 1;
	while(input[i + j] && input[i + j] != '\'')
		j++;
	if (input[i + j] == '\'')
		j++;
	return (j);
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

t_token *tokenize(char *input, t_token *table)
{
    char **tokens;
    char *converted_input;
    
    converted_input = str_sel_dup(input);
    tokens = ft_split(converted_input, SEP);
    table = convert_to_lst(tokens, table, NULL, NULL);
    return (table);
}
