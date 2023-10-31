/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:44:28 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/30 19:58:54 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static int in_single(char *input, int i)
{
	int j;

	j = 0;
	while(input[++i])
	{
		if(input[i] == '\'')
		{
			j += 2;
			break ;
		}
		j++;
	}
	if (input[i] != '\'')
		j = ERROR;
	return (j);
}

static int in_double(char *input, int i)
{
	int j;

	j = 0;
	while(input[++i])
	{
		if(input[i] == '\"')
		{
			j += 2;
			break ;
		}
		j++;
	}
	if (input[i] != '\"')
		j = ERROR;
	return (j);
}

char **tokenize(char *input)
{
	int i;
	int j;
	char **tokens;
	
	i = 0;
	while(input[i])
	{
		j = 0;
		if (input[i] == '\'')
			j = in_single(input, i);
		else if (input[i] == '\"')
			j = in_double(input, i);
		else if (isspace(input[i]))
			input[i++] = SEP;
		else
			i++;
		if (j != ERROR)
			i += j;
		else
			return (NULL);
	}
	tokens = ft_split(input, SEP);
	return(tokens);
}
