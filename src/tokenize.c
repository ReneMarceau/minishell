/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:44:28 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/08 20:29:27 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static int handle_special(char *input, int i)
{
	int j;

	j = 0;
	if (input[i] == '$')
		j = 0; //modify
		// j = expand_one(input, i);
	else if (input[i] == '<')
		j = 0; //to modify
	return (j); //same 
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
		else if (ft_isspecial(input[i]))
			j = handle_special(input, i);
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



// static create_token(t_cmd *tokens, char *input, int i, int last)
// {
// 	int j;
// 	char *new;

// 	if (last == INVALID)
// 	{
// 		j = 0;
// 		tokens.token = ft_substr(input)
		
// 	}
// 	else
// 	{

		
// 	}


	
// }




// static int new_token(t_cmd *tokens, char *input, int i)
// {
// 	static int last = INVALID;
// 	int j;
	
// 	j = 0;
// 	create_token(tokens, input, i, last);


// 	last = i;
// 	return (j);	
// }


// int make_tokens(t_cmd *tokens, char *input)
// {
// 	int i;
// 	int j;
// 	int last;

// 	last = 0;
// 	i = 0;
// 	while(input[i])
// 	{
// 		j = 0;
// 		if (input[i] == '\'')
// 			j = in_single(input, i);
// 		else if (input[i] == '\"')
// 			j = in_double(input, i);
// 		else if (is_sep(input[i]))
// 			j = new_token(tokens, input, i);
// 		else
// 			i++
// 		if (j != ERROR)
// 			i += j;
// 		else
// 			return (NULL);
// 	}	
// }




static int create_space(char *input, int i, int space)
{
		

	
}

static int sep_special(char *input, int i)
{
	int j;
	int check;
	
	j = 0;
	if (i == 0 || !input[i + 1])
		check = create_space(input, i, 1);
	
	
}

char **make_tokens(char **tokens, char *input)
{
	int i;
	int j;
	int last;
	
	last = 0;
	i = 0;
	while(input[i])
	{
		j = 0;
		if (ft_isquote(input[i]))
			j = in_quote(input, i);
		else if (ft_isspecial(input[i]))
			j = sep_special(input[i]);
		else if (ft_isspace(input[i]))
			input[i] = SEP;
		else
			i++
		if (j != ERROR)
			i += j;
		else
			return (NULL);
	}
}

