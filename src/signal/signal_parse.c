/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:17:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/05 20:22:09 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int *if_sig_int(int context, t_shell *shell)
{
	static int sig_check = 0;

	if (context)
		sig_check = context;	
	return (&sig_check);
}
