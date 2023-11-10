/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:30:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/09 21:23:21 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

size_t count_tokens(t_cmd *table)
{
	size_t i;

	i = 0;
	while(table->args[i])
		i++;
	return (i);	
}


// void assign_token(t_args *table)
// {
	



// }
