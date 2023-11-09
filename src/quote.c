/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:07:27 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/08 19:58:32 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int in_single(char *input, int i)
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

int in_double(char *input, int i)
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

int in_quote(char *input, int i)
{
	int j;

	j = 0;
	if (input[i] == '\'')
		j += in_single(input, i);
	if (input[i] == '\"')
		j += in_double(input, i); 
	return (j);
}

