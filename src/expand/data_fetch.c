/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_fetch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:20:56 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/14 18:33:52 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

size_t	len_ext(char *env)
{
	size_t	i;
	size_t	res;

	res = 0;
	i = 0;
	while (env[i] != '=')
		i++;
	i++;
	while (env[i++])
		res++;
	return (res);
}

char *the_recovery(char *line)
{
	char	*new;
	
	new = NULL;
	new = ft_strdup(line);
	if (new == NULL)
		return (NULL);
	return (new);
}
