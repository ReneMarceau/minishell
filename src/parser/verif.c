/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:23:34 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/14 18:44:26 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"

static bool reached_limit(char *input, size_t i)
{
	const char special = input[i];

	i++;
	if (input[i])
	{
		if (special == '|' && input[i] == special)
			return (true);
		if (special != '|' && input[i])
			if (input[i + 1] == special)
				return (true);
	}
	return (false);
}

bool check_token(char *input)
{
	size_t  i;

	i = 0;
	while (input[i])
	{
		if (ft_isquote(input[i]))
			i += through_quote(input, i, NULL, false);
		else if (ft_isspecial(input[i]))
		{
			if (reached_limit(input, i))
				return (false);
			else
				i += through_special(input, i);
		}
		else
			i++;
	}
	return (true);
}

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
	return(false);
}

int check_s_quote(char *input, int pos)
{
	int i;

	i = 0;
	while (input[++pos])
	{
		i++;
		if (input[pos] == '\'')
			return (i);
	}
	return(false);
}

bool check_quotes(char *input)
{
	int check;
	int i;

	i = 0;
	while(input[i])
	{
		check = 0;
		if (input[i] == '"')
		{
			check = check_d_quote(input, i);
			if (check == false)
				return(false);
			i += check + 1;
		}
		else if (input[i] == '\'')
		{
			check = check_s_quote(input, i);
			if (check == false)
				return(false);
			i += check + 1;
		}
		if (!check)
			i++;
	}
	return (true);
}
