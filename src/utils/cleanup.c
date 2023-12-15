/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:52:40 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/15 14:29:01 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "global.h"

bool	close_pipes(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < (shell->nb_cmd - 1))
	{
		if (close(shell->pipe_fd[i][READ_END]) == -1)
			return (print_error(ERR_CLOSE, NULL, EXIT_FAILURE), false);
		if (close(shell->pipe_fd[i][WRITE_END]) == -1)
			return (print_error(ERR_CLOSE, NULL, EXIT_FAILURE), false);
		i++;
	}
	return (true);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
