/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:44:28 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/27 23:14:57 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

char *tokenize(char *input)
{
	int i;
	char **tokens;
	bool inquote;
	
	i = 0;
	inquote = FALSE;
	while(input[i])
	{
		while(ft_isspace(input[i]))
		{
			if(!inquote)
				input[i] = 19;
			i++;
		}
		while(!ft_isspace(input[i]))
		{
			if (input[i] == "'" && !inquote)
				inquote = !inquote;
			i++;
		}
	}
	tokens = ft_split(input, 19);
	
}
