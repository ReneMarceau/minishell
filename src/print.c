/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:52:48 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/10 20:57:12 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int printm(char *message)
{
	printf("%s\n", message);
	return(TRUE);
}

void print_lst(t_args *head) 
{
    t_args *current = head;

    while (current != NULL) 
	{
        printf("%s\n", (char *)current->token);
        current = current->next;
    }
}
