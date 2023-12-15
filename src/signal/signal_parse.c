/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:17:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/15 13:51:56 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_signal	*sig_state(int context)
{
	static t_signal	sig_check;

	if (context)
	{
		if (context == RESET_SIG)
			sig_check.type = FALSE;
		else
			sig_check.type = context;
	}
	return (&sig_check);
}
