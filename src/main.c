/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:44:19 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/16 22:00:31 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_shell *shell = malloc(sizeof(t_shell*));
	t_args *arg;
	(void)argc;
	(void)argv;
	int i;
	shell->env = envp;
	// int i = 0; //rm
	// while(envp[i])
	// 	printf("%s\n", envp[i++]);
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
				// printf("Added to history: %s\n", input);
			arg = parse(input, shell);
			if (arg)
				printf("-----------\n");
			else
				printf("Command not found\n");
		}
		free(input);
	}
	free(input);
	free(shell);
	return (0);
}
