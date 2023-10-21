/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:44:19 by rmarceau          #+#    #+#             */
/*   Updated: 2023/10/20 20:04:45 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int main(int argc, char** argv, char** env) 
{
    char	*input;
	(void)argc;
	(void)argv;
	(void)env;
	while (1) {
		input = readline("minishell> ");
		
		if (input == NULL) 
		{
			printf("exit\n");
			break;
		}
		if (input && *input) 
		{
			add_history(input);
			printf("Added to history: %s\n", input);
		}
		free(input);
	}
    return (0);
}
