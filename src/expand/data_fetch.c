/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_fetch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:20:56 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/17 14:54:28 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

char **fetch_envp(char **init)
{
	static char **envp;
	
	if (init)
		envp = init;
	return(envp);
}

size_t len_ext(char *env)
{
	size_t i;
	size_t res;

	res = 0;
	i = 0;
	while(env[i] != '=')
		i++;
	i++;
	while(env[i++])
		res++;
	return (res);
}
