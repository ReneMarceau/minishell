/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:44:19 by rmarceau          #+#    #+#             */
/*   Updated: 2023/09/24 16:16:18 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int main(void) {
    char	*input;

	while (1) {
		input = readline("minishell> ");
		
		if (input == NULL) {
			printf("exit\n");
			break;
		}

		if (input && *input) {
			add_history(input);
			printf("Added to history: %s\n", input);
		}
	
		free(input);
	}
    return (0);
}