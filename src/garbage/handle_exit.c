/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:21:45 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/28 13:27:34 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"

void exit_shell(char *err_message)
{
	if (err_message != NULL)
		print_error(err_message, NULL);
	all_free();
	exit(g_exit_status);
}
