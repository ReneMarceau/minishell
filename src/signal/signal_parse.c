/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:17:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/05 19:22:56 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int *if_sig_int(int context, t_shell *shell)
{
	static int sig_check = 0;

	if (context)
	{
		

		
	}
	return (&sig_check);
}

// void sig_handle(t_shell *shell, int type)
// {
// 	// sigemptyset(&shell->sa.sa_mask);
// 	// shell->sa.sa_flags = SA_SIGINFO;
// 	// if (type == SIGINT_INTER)
// 	// {
// 	// 	sa.sa_sigaction = treat_sig;
// 	// 	sigaction(SIGINT, &sa, NULL);
// 	// }
// 	// if (type == SIGINT_HERE)
// 	// {
// 	// 	sa.sa_sigaction = treat_here;
// 	// 	sigaction(SIGINT, &sa, NULL);
// 	// }
// 	// sigaction(SIGQUIT, &sa, NULL);
// }
