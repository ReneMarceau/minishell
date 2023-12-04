/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:17:51 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/04 17:06:52 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "signals.h"

int *if_sigint(int condition)
{
	static int sig_check = 0;

	if (condition)
		sig_check = condition;
	return (&sig_check);
}

void sig_handle(t_shell *shell, int type)
{
	struct sigaction sa;
	
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	(void)shell;
	if (type == SIGINT_INTER)
	{
		sa.sa_sigaction = treat_sig;
		sigaction(SIGINT, &sa, NULL);
	}
	if (type == SIGINT_HERE)
	{
		sa.sa_sigaction = treat_here;
		sigaction(SIGINT, &sa, NULL);
	}
	// sigaction(SIGQUIT, &sa, NULL);
}
