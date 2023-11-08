/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:03:30 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/07 23:10:52 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

// static size_t check_initial(char *input)
// {
// 	if(input != NULL)
// 	{

		
// 	}

// }
static size_t do_quote(char *input, int i)
{
	int j;

	j = 0;
	while(input[i])
}

static size_t go_through(char *input, int i, char c)
{
	size_t j;

	j = 0;
	if (ft_isspace(c))
	{
		j++;
		while(ft_isspace(input[++i]))
			j++;
		return (j);
	}
	while (input[++i])
	{
		j++;
		if (input[i] != c)
			break ;
	}
	if (ft_isspace(c))
	{
		j++;
		while(ft_isspace(input[++i]))
			j++;
	}
	return (j);
}

size_t count_arg(char *input, size_t i, size_t res)
{
	if (ft_isspace(input[i]))
		i += go_through(input, i, ' ');
	while(input[i])
	{
		if (ft_isquote(input[i]))
			
		else if (ft_isspace(input[i]))
		{
			i += go_through(input, i, ' ');
			res++;
		}
		else if (ft_isspecial(input[i]))
		{
			i += go_through(input, i, input[i]);
			if (ft_isspace(input[i]))
				go_through(input, i, ' ');
			res++;
		}
		else
			i++;
	}
	return (res);
}
