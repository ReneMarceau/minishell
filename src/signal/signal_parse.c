/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:17:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/06 10:40:10 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int *if_sig_int(int context, t_shell *shell)
{
	static int sig_check = 0;

	(void)shell;
	if (context)
		sig_check = context;	
	return (&sig_check);
}
