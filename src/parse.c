/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:23:34 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/07 22:56:27 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

// static void test_malloc(void)
// {
// 	// t_test *a = NULL;
// 	// gmallock(a);
// 	// if(!a)
// 	// 	printf("yes\n");
// 	// clean_mem();
// }

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
	// test_malloc();
	t_cmd parse;
	// parse.args = tokenize(input);
	printf("argcount: %zu\n", count_arg(input));
	if (parse.args == NULL)
		return(FALSE);
	// int i = 0;
	// while(parse.args[i])
	// 	printf("%s\n", parse.args[i++]);
	// expand_tokens(parse.args);
	// printf("%s\n", parse.args[1]);
	// if (!check_quotes(input))
	// 	return(FALSE);
	return(TRUE);
}




// char **lexer()
// {


	
// }