/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:16 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/10 22:25:42 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"



static bool expand_one(t_args* current, size_t pos, bool in_quote)
{
	

	
}

// static size_t expand_in_quote(void *token, size_t pos)
// {


	
// }


static size_t check_in_quote(t_args *current, size_t pos)
{
	size_t i;

	i = 1;
	while(current->token[pos + i] != '\"')
	{
		if (current->token[pos + i] == '$')
			i += expand_one(current, pos + i, TRUE);
		i++;	
	}
	return (i);
}

static bool check_to_expand(t_args *current)
{
	size_t i;
	
	i = 0;
	while(current->token[i])
	{
		if (current->token[i] == '\'')
			i += through_quote(current->token, i, NULL, FALSE);
		else if (current->token[i] == '\"')
			i += check_in_quote(current, i)
	

	
	}
	
}



bool expand_tokens(t_args *head)
{
	t_args *current;
	bool check;

	check = FALSE;
	current = head;
	while(current)
	{
		if (current->type == STR)
		{
			check = check_to_expand(current);
			if (check == FALSE)
				return (FALSE);
		}
		current = current->next;
	}
	return (TRUE);
}

























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
