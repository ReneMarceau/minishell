/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:23:34 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/14 12:01:17 by wmillett         ###   ########.fr       */
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

static bool reached_limit(char *input, size_t i)
{
	const char special = input[i];
	bool limit;

	limit = FALSE;
	i++;
	if (input[i])
	{
		if (special == '|' && input[i] == special)
			return (TRUE);
		if (special != '|' && input[i])
			if (input[i + 1] == special)
				return (TRUE);
	}
	return (FALSE);
}

bool check_token(char *input)
{
	size_t i;
	char tmp;

	tmp = 0;
	i = 0;
	while(input[i])
	{
		if (ft_isquote(input[i]))
			i += through_quote(input, i, NULL, FALSE);
		else if (ft_isspecial(input[i]))
		{
			if (reached_limit(input, i))
				return (FALSE);
			else
				i += through_special(input, i);
		}
		else
			i++;
	}
	return (TRUE);
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

bool check_quotes(char *input)
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

t_args *parse(char *input)
{
	t_args *table;
	// t_args *tmp; //test

	table = NULL;
	// table = malloc(sizeof(t_args*));
	// if (table == NULL)
	// 	return (NULL);
	if (!check_quotes(input) || !check_token(input))
		return (NULL);
	table = tokenize(input, table);
	if (table == NULL)
		return (NULL);
	print_lst(table);
	// expand_tokens(table);
	printf("after expansion ---------\n");
	print_lst(table);
	// int i = 0;
	
	// while(table->args[i])
	// 	printf("%s\n", table->args[i++]);
	// expand_tokens(table.args);
	
	// printf("%s\n", table->token);
	// while (table->token)
	// {
	// 	printf("%s\n", table->token);
	// 	table = table->next;
	// }
	return(table);
}




// char **lexer()
// {


	
// }