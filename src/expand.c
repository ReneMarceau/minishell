/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:16 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/30 22:34:17 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"




// static int expand_dollar(char **tokens, int i, int j)
// {
	

	
// }



// static int single_quote(char **tokens, int i, int j)
// {



	
// }



// static int double_quote(char **tokens, int i, int j)
// {



	
// }

// int expand_tokens(char **tokens)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (tokens[i])
// 	{
// 		j = 0;
// 		while(tokens[i][j])
// 		{
// 			if (tokens[i][j] == '\'')
// 				j = single_quote(tokens, i, j);
// 			else if (tokens[i][j] == '\"')
// 				j = double_quote(tokens, i, j);
// 			else if (tokens[i][j] == '$')
// 				expand_dollar(tokens, i, j);
// 			else
// 				j++;
// 			if (j != ERROR)
// 				i += j;
// 			else
// 				return (0);
// 		}
// 		i++;
// 	}

// 	return(TRUE);
// }
