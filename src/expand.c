/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:16 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/07 22:55:04 by wmillett         ###   ########.fr       */
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




// char *expand_dup(char *arg, int start, int end)
// {
// 	char *s1;
// 	char *s2;
// 	const char *s3 = ft_substr(arg, end, ft_strlen(arg + end));

// 	if (start == 0)
// 	{
// 		s1 = ft_substr(arg, start, end - start);
// 	}
// 	else
// 	{
		

// 	}
// 	// s1 = ft_strdup()
	
// }





// int to_expand(char *arg, int pos)
// {
// 	int i;

// 	i = pos;
// 	if (arg[i + 1] == '$')
// 		return (FALSE);
// 	while(arg[++i])
// 		if (!ft_isalnum(arg[i]) && arg[i] != '_')
// 			break ;
// 	return(expand_dup(arg, pos, i));
// }


// int expand_one(char *arg, int pos)
// {


	
// }