/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:06:36 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/07 16:52:12 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	free_double_char(char **lst)
{
	size_t	i;

	i = 0;
	while (lst[i])
		free(lst[i++]);
}

char	*clean_all(void)
{
	all_free();
	return (NULL);
}
