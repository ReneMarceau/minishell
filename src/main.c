/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:44:19 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/07 22:56:12 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	(void)envp;
	signalhandler();
	while (TRUE)
	{
		input = readline("minishell> ");
		if (input == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (input && *input)
		{
			add_history(input);
			if (parse(input))
				printf("Added to history: %s\n", input);
			else
				printf("Command not found\n");
		}
		free(input);
	}
	free(input);
	return (0);
}
