/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:16 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/30 20:20:19 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"



static int single_quote()
{



	
}



static int double_quote()
{



	
}






int expand_tokens(char **tokens)
{
	int i;
	int j;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		while(tokens[i][j])
		{
			if (tokens[i][j] == '\'')
			j = single_quote(tokens, i, j);
			else if (tokens[i][j] == '\"')
				j = double_quote(tokens, i, j);
			else if (tokens[i][j] == '$')
				expand_dollar(tokens, i, j);
			else
				j++;
			if (j != ERROR)
				i += j;
			else
				return (NULL);
			
		}
		i++;
	}





	return(TRUE);
}
