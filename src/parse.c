/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:23:34 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/22 22:11:03 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int check_d_quote(char *input, int pos)
{
	int i;

	i = 0;
	while(input[++pos])
	{
		i++;
		if(input[pos] == '"')
			return (i);
	}
	return(FALSE);
}

int check_s_quote(char *input, int pos)
{
	int i;

	i = 0;
	while(input[++pos])
	{
		i++;
		if(input[pos] == '\'')
			return (i);
	}
	return(FALSE);
}

int check_quotes(char *input)
{
	int i;
	int check;

	i = 0;
	while(input[i])
	{
		check = 0;
		if (input[i] == '"')
		{
			check = (check_d_quote(input, i));
			if (check == FALSE)
				return(FALSE);
			i += check + 1;
		}
		else if (input[i] == '\'')
		{
			check = (check_s_quote(input, i));
			if (check == FALSE)
				return(FALSE);
			i += check + 1;
		}
		if (!check)
			i++;
	}
	return(TRUE);
}

int parse(char *input)
{
	
	if (!check_quotes(input))
		return(FALSE);
	return(TRUE);
}




// char **lexer()
// {


	
// }