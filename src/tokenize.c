/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:44:28 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/27 23:05:09 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

char *tokenize(char *input)
{
	int i;
	
	i = 0;
	while(input[i])
	{
		while(ft_isspace(input[i]))
			input[i++] = 19;
		while(!ft_isspace(input[i]))
			i++;
	}
	ft_split(input, 19);
	
}
